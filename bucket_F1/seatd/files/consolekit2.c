#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include <basu/sd-bus.h>
#pragma GCC diagnostic pop

#include "backend.h"
#include "drm.h"
#include "libseat.h"
#include "log.h"

#if defined(__FreeBSD__)
#include <sys/param.h>

static int dev_is_drm(dev_t device) {
	char name[SPECNAMELEN + sizeof("/dev/")] = "/dev/";

	if (!devname_r(device, S_IFCHR, name + sizeof("/dev/") - 1,
		       sizeof(name) - sizeof("/dev/") - 1))
		return 0;

	return path_is_drm(name);
}

#elif defined(__linux__)

static int dev_major_is_drm(unsigned int dev_major) {
	return dev_major == 226;
}

static int dev_is_drm(dev_t device) {
	return dev_major_is_drm(major(device));
}

#endif

struct backend_consolekit2 {
	struct libseat base;
	const struct libseat_seat_listener *seat_listener;
	void *seat_listener_data;

	sd_bus *bus;
	char *path;
	char *seat_path;
	char *seat;

	bool active;
	bool initial_setup;
	int has_drm;
};

const struct seat_impl consolekit2_impl;
static struct backend_consolekit2 *backend_consolekit2_from_libseat_backend(struct libseat *base);
static void release_control(struct backend_consolekit2 *backend);

static void destroy(struct backend_consolekit2 *backend) {
	assert(backend);
	if (backend->bus != NULL) {
		sd_bus_unref(backend->bus);
	}
	free(backend->path);
	free(backend->seat_path);
	free(backend->seat);
	free(backend);
}

static int close_seat(struct libseat *base) {
	struct backend_consolekit2 *backend = backend_consolekit2_from_libseat_backend(base);
	release_control(backend);
	destroy(backend);
	return 0;
}

static int ping_handler(sd_bus_message *m, void *userdata, sd_bus_error *ret_error) {
	(void)ret_error;
	(void)userdata;
	if (sd_bus_message_is_method_error(m, NULL)) {
		const sd_bus_error *error = sd_bus_message_get_error(m);
		log_errorf("Ping failed: %s: %s", error->name, error->message);
		return -1;
	}
	return 0;
}

static int send_ping(struct backend_consolekit2 *backend) {
	int ret = sd_bus_call_method_async(backend->bus, NULL, "org.freedesktop.ConsoleKit",
					   "/org/freedesktop/ConsoleKit/Manager", "org.freedesktop.DBus.Peer",
					   "Ping", ping_handler, backend, "");
	if (ret < 0) {
		return ret;
	}
	return 0;
}

static void check_pending_events(struct backend_consolekit2 *backend) {
	uint64_t queued_read, queued_write;
	sd_bus_get_n_queued_read(backend->bus, &queued_read);
	sd_bus_get_n_queued_write(backend->bus, &queued_write);

	if (queued_read == 0 && queued_write == 0) {
		return;
	}

	// The sd_bus instance has queued data, so a dispatch is required.
	// However, we likely already drained our socket, so there will not be
	// anything to read. Instead, send a ping request to logind so that the
	// user will be woken up by its response.
	int ret = send_ping(backend);
	if (ret < 0) {
		log_errorf("Could not send ping message: %s", strerror(-ret));
		return;
	}
}

static int open_device(struct libseat *base, const char *path, int *fd) {
	struct backend_consolekit2 *session = backend_consolekit2_from_libseat_backend(base);

	int ret;
	int tmpfd = -1;
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	struct stat st;
	if (stat(path, &st) < 0) {
		log_errorf("Could not stat path '%s'", path);
		return -1;
	}

	ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
				 "org.freedesktop.ConsoleKit.Session", "TakeDevice", &error, &msg,
				 "uu", major(st.st_rdev), minor(st.st_rdev));
	if (ret < 0) {
		log_errorf("Could not take device: %s", error.message);
		tmpfd = -1;
		goto out;
	}

	int paused = 0;
	ret = sd_bus_message_read(msg, "hb", &tmpfd, &paused);
	if (ret < 0) {
		log_errorf("Could not parse D-Bus response: %s", strerror(-ret));
		tmpfd = -1;
		goto out;
	}

	// The original fd seems to be closed when the message is freed
	// so we just clone it.
	tmpfd = fcntl(tmpfd, F_DUPFD_CLOEXEC, 0);
	if (tmpfd < 0) {
		log_errorf("Could not duplicate fd: %s", strerror(errno));
		tmpfd = -1;
		goto out;
	}

	if (dev_is_drm(st.st_rdev)) {
		session->has_drm++;
		log_debugf("DRM device opened, current total: %d", session->has_drm);
	}

	*fd = tmpfd;
out:
	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	check_pending_events(session);
	return tmpfd;
}

static int close_device(struct libseat *base, int device_id) {
	struct backend_consolekit2 *session = backend_consolekit2_from_libseat_backend(base);
	if (device_id < 0) {
		errno = EINVAL;
		return -1;
	}

	int fd = device_id;

	struct stat st = {0};
	if (fstat(fd, &st) < 0) {
		log_errorf("Could not stat fd %d", fd);
		return -1;
	}
	if (dev_is_drm(st.st_rdev)) {
		session->has_drm--;
		log_debugf("DRM device closed, current total: %d", session->has_drm);
		assert(session->has_drm >= 0);
	}

	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;
	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
				     "org.freedesktop.ConsoleKit.Session", "ReleaseDevice", &error,
				     &msg, "uu", major(st.st_rdev), minor(st.st_rdev));
	if (ret < 0) {
		log_errorf("Could not close device: %s", error.message);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);

	check_pending_events(session);
	return ret < 0 ? -1 : 0;
}

static int switch_session(struct libseat *base, int s) {
	struct backend_consolekit2 *session = backend_consolekit2_from_libseat_backend(base);
	if (s < 0) {
		errno = EINVAL;
		return -1;
	}

	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->seat_path,
				     "org.freedesktop.ConsoleKit.Seat", "SwitchTo", &error, &msg,
				     "u", (uint32_t)s);
	if (ret < 0) {
		log_errorf("Could not switch session: %s", error.message);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	check_pending_events(session);
	return ret < 0 ? -1 : 0;
}

static int disable_seat(struct libseat *base) {
	(void)base;
	return 0;
}

static int get_fd(struct libseat *base) {
	struct backend_consolekit2 *backend = backend_consolekit2_from_libseat_backend(base);
	int fd = sd_bus_get_fd(backend->bus);
	if (fd >= 0) {
		return fd;
	}

	errno = -fd;
	return -1;
}

static int poll_connection(struct backend_consolekit2 *backend, int timeout) {
	struct pollfd fd = {
		.fd = sd_bus_get_fd(backend->bus),
		.events = POLLIN,
	};

	if (poll(&fd, 1, timeout) == -1) {
		if (errno == EAGAIN || errno == EINTR) {
			return 0;
		} else {
			return -1;
		}
	}

	if (fd.revents & (POLLERR | POLLHUP)) {
		errno = ECONNRESET;
		return -1;
	}
	return 0;
}

static int dispatch_and_execute(struct libseat *base, int timeout) {
	struct backend_consolekit2 *backend = backend_consolekit2_from_libseat_backend(base);
	if (backend->initial_setup) {
		backend->initial_setup = false;
		if (backend->active) {
			backend->seat_listener->enable_seat(&backend->base,
							    backend->seat_listener_data);
		} else {
			backend->seat_listener->disable_seat(&backend->base,
							     backend->seat_listener_data);
		}
	}

	int total_dispatched = 0;
	int dispatched = 0;
	while ((dispatched = sd_bus_process(backend->bus, NULL)) > 0) {
		total_dispatched += dispatched;
	}
	if (total_dispatched == 0 && timeout != 0) {
		if (poll_connection(backend, timeout) == -1) {
			log_errorf("Could not poll connection: %s", strerror(errno));
			return -1;
		}
		while ((dispatched = sd_bus_process(backend->bus, NULL)) > 0) {
			total_dispatched += dispatched;
		}
	}
	check_pending_events(backend);
	return total_dispatched;
}

static const char *seat_name(struct libseat *base) {
	struct backend_consolekit2 *backend = backend_consolekit2_from_libseat_backend(base);
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	int ret = sd_bus_call_method(backend->bus, "org.freedesktop.ConsoleKit", backend->seat_path,
				     "org.freedesktop.ConsoleKit.Seat", "GetName", &error, &msg, "");
	if (ret < 0) {
		log_errorf("Could not get seat name: %s", error.message);
	} else {
		const char *seat;
		ret = sd_bus_message_read(msg, "s", &seat);
		backend->seat = strdup(seat);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	return backend->seat;
}

static struct backend_consolekit2 *backend_consolekit2_from_libseat_backend(struct libseat *base) {
	assert(base->impl == &consolekit2_impl);
	return (struct backend_consolekit2 *)base;
}

static int session_activate(struct backend_consolekit2 *session) {
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	// Note: the Activate call might not make the session active immediately
	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
				     "org.freedesktop.ConsoleKit.Session", "Activate", &error, &msg,
				     "");
	if (ret < 0) {
		log_errorf("Could not activate session: %s", error.message);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	return ret;
}

static int session_check_active(struct backend_consolekit2 *session) {
	sd_bus_error error = SD_BUS_ERROR_NULL;
	int active = 0;
	int ret = sd_bus_get_property_trivial(session->bus, "org.freedesktop.ConsoleKit", session->path,
					      "org.freedesktop.ConsoleKit.Session", "active", &error,
					      'b', &active);
	if (ret < 0) {
		log_errorf("Could not check if session is active: %s", error.message);
	} else {
		session->active = (bool)active;
	}

	sd_bus_error_free(&error);
	return ret;
}

static int take_control(struct backend_consolekit2 *session) {
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
				     "org.freedesktop.ConsoleKit.Session", "TakeControl", &error,
				     &msg, "b", false);
	if (ret < 0) {
		log_errorf("Could not take control of session: %s", error.message);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	return ret;
}

static void release_control(struct backend_consolekit2 *session) {
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
				     "org.freedesktop.ConsoleKit.Session", "ReleaseControl", &error,
				     &msg, "");
	if (ret < 0) {
		log_errorf("Could not release control of session: %s", error.message);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
}

static void set_active(struct backend_consolekit2 *backend, bool active) {
	if (backend->active == active) {
		return;
	}

	backend->active = active;
	if (active) {
		log_info("Enabling seat");
		backend->seat_listener->enable_seat(&backend->base, backend->seat_listener_data);
	} else {
		log_info("Disabling seat");
		backend->seat_listener->disable_seat(&backend->base, backend->seat_listener_data);
	}
}

static int pause_device(sd_bus_message *msg, void *userdata, sd_bus_error *ret_error) {
	struct backend_consolekit2 *session = userdata;

	uint32_t major, minor;
	const char *type;
	int ret = sd_bus_message_read(msg, "uus", &major, &minor, &type);
	if (ret < 0) {
		log_errorf("Could not parse D-Bus response: %s", strerror(-ret));
		return 0;
	}

	if (dev_is_drm(makedev(major, minor)) && strcmp(type, "gone") != 0) {
		log_debugf("DRM device paused: %s", type);
		assert(session->has_drm > 0);
		set_active(session, false);
	}

	if (strcmp(type, "pause") == 0) {
		ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
					 "org.freedesktop.ConsoleKit.Session",
					 "PauseDeviceComplete", ret_error, &msg, "uu", major, minor);
		if (ret < 0) {
			log_errorf("Could not send PauseDeviceComplete signal: %s",
				   ret_error->message);
		}
	}

	return 0;
}

static int resume_device(sd_bus_message *msg, void *userdata, sd_bus_error *ret_error) {
	(void)ret_error;
	struct backend_consolekit2 *session = userdata;
	int ret;

	int fd;
	uint32_t major, minor;
	ret = sd_bus_message_read(msg, "uuh", &major, &minor, &fd);
	if (ret < 0) {
		log_errorf("Could not parse D-Bus response: %s", strerror(-ret));
		return 0;
	}

	if (dev_is_drm(makedev(major, minor))) {
		log_debug("DRM device resumed");
		assert(session->has_drm > 0);
		set_active(session, true);
	}

	return 0;
}

static int properties_changed(sd_bus_message *msg, void *userdata, sd_bus_error *ret_error) {
	(void)ret_error;
	struct backend_consolekit2 *session = userdata;
	int ret = 0;

	if (session->has_drm > 0) {
		return 0;
	}

	// PropertiesChanged arg 1: interface
	const char *interface;
	ret = sd_bus_message_read_basic(msg, 's', &interface); // skip path
	if (ret < 0) {
		goto error;
	}

	bool is_session = strcmp(interface, "org.freedesktop.ConsoleKit.Session") == 0;
	bool is_seat = strcmp(interface, "org.freedesktop.ConsoleKit.Seat") == 0;
	if (!is_session || !is_seat) {
		// not interesting for us; ignore
		return 0;
	}

	// PropertiesChanged arg 2: changed properties with values
	ret = sd_bus_message_enter_container(msg, 'a', "{sv}");
	if (ret < 0) {
		goto error;
	}

	const char *s;
	while ((ret = sd_bus_message_enter_container(msg, 'e', "sv")) > 0) {
		ret = sd_bus_message_read_basic(msg, 's', &s);
		if (ret < 0) {
			goto error;
		}

		if (is_session && strcmp(s, "Active") == 0) {
			int ret;
			ret = sd_bus_message_enter_container(msg, 'v', "b");
			if (ret < 0) {
				goto error;
			}

			bool value;
			ret = sd_bus_message_read_basic(msg, 'b', &value);
			if (ret < 0) {
				goto error;
			}

			log_debugf("%s state changed: %d", s, value);
			set_active(session, value);
			return 0;
		} else {
			sd_bus_message_skip(msg, "{sv}");
		}

		ret = sd_bus_message_exit_container(msg);
		if (ret < 0) {
			goto error;
		}
	}

	if (ret < 0) {
		goto error;
	}

	ret = sd_bus_message_exit_container(msg);
	if (ret < 0) {
		goto error;
	}

	// PropertiesChanged arg 3: changed properties without values
	sd_bus_message_enter_container(msg, 'a', "s");
	while ((ret = sd_bus_message_read_basic(msg, 's', &s)) > 0) {
		if (is_session && strcmp(s, "Active") == 0) {
			sd_bus_error error = SD_BUS_ERROR_NULL;
			const char *obj = "org.freedesktop.ConsoleKit.Session";
			const char *field = "Active";
			bool value;
			ret = sd_bus_get_property_trivial(session->bus, "org.freedesktop.ConsoleKit",
							  session->path, obj, field, &error, 'b',
							  &value);
			if (ret < 0) {
				log_errorf("Could not get '%s' property: %s", field, error.message);
				return 0;
			}

			log_debugf("%s state changed: %d", field, value);
			set_active(session, value);
			return 0;
		}
	}

error:
	if (ret < 0) {
		log_errorf("Could not parse D-Bus PropertiesChanged: %s", strerror(-ret));
	}

	return 0;
}

static int add_signal_matches(struct backend_consolekit2 *backend) {
	static const char *consolekit2 = "org.freedesktop.ConsoleKit";
	static const char *session_interface = "org.freedesktop.ConsoleKit.Session";
	static const char *property_interface = "org.freedesktop.DBus.Properties";
	int ret;

	ret = sd_bus_match_signal(backend->bus, NULL, consolekit2, backend->path, session_interface,
				  "PauseDevice", pause_device, backend);
	if (ret < 0) {
		log_errorf("Could not add D-Bus match: %s", strerror(-ret));
		return ret;
	}

	ret = sd_bus_match_signal(backend->bus, NULL, consolekit2, backend->path, session_interface,
				  "ResumeDevice", resume_device, backend);
	if (ret < 0) {
		log_errorf("Could not add D-Bus match: %s", strerror(-ret));
		return ret;
	}

	ret = sd_bus_match_signal(backend->bus, NULL, consolekit2, backend->path, property_interface,
				  "PropertiesChanged", properties_changed, backend);
	if (ret < 0) {
		log_errorf("Could not add D-Bus match: %s", strerror(-ret));
		return ret;
	}

	ret = sd_bus_match_signal(backend->bus, NULL, consolekit2, backend->seat_path,
				  property_interface, "PropertiesChanged", properties_changed,
				  backend);
	if (ret < 0) {
		log_errorf("Could not add D-Bus match: %s", strerror(-ret));
		return ret;
	}

	return 0;
}

static bool get_display_session(struct backend_consolekit2 *session) {
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	// XXX: XDG_SESSION_ID?

	// If there's a session active for the current process then just use
	// that
	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit",
				     "/org/freedesktop/ConsoleKit/Manager",
				     "org.freedesktop.ConsoleKit.Manager", "GetSessionByPID",
				     &error, &msg, "u", getpid());
	if (ret < 0) {
		log_errorf("Could not get session: %s", error.message);
		session->path = NULL;
	} else {
		const char *path;
		ret = sd_bus_message_read(msg, "o", &path);
		if (ret < 0) {
			log_errorf("Could not parse D-Bus response: %s", strerror(-ret));
			session->path = NULL;
		} else {
			session->path = strdup(path);
		}
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	return session->path != NULL;
}

static int get_session_seat(struct backend_consolekit2 *session) {
	sd_bus_message *msg = NULL;
	sd_bus_error error = SD_BUS_ERROR_NULL;

	int ret = sd_bus_call_method(session->bus, "org.freedesktop.ConsoleKit", session->path,
				     "org.freedesktop.ConsoleKit.Session", "GetSeatId", &error,
				     &msg, "");
	if (ret < 0) {
		free(session->seat_path);
		session->seat_path = NULL;
	} else {
		const char *path;
		ret = sd_bus_message_read(msg, "o", &path);
		session->seat_path = strdup(path);
	}

	sd_bus_error_free(&error);
	sd_bus_message_unref(msg);
	return ret;
}

static struct libseat *consolekit2_open_seat(const struct libseat_seat_listener *listener, void *data) {
	struct backend_consolekit2 *backend = calloc(1, sizeof(struct backend_consolekit2));
	if (backend == NULL) {
		return NULL;
	}

	int ret = sd_bus_default_system(&backend->bus);
	if (ret < 0) {
		goto error;
	}

	if (!get_display_session(backend)) {
		goto error;
	}

	ret = get_session_seat(backend);
	if (ret < 0) {
		goto error;
	}

	ret = add_signal_matches(backend);
	if (ret < 0) {
		goto error;
	}

	ret = session_activate(backend);
	if (ret < 0) {
		goto error;
	}

	ret = session_check_active(backend);
	if (ret < 0) {
		goto error;
	}

	ret = take_control(backend);
	if (ret < 0) {
		goto error;
	}

	backend->initial_setup = true;
	backend->seat_listener = listener;
	backend->seat_listener_data = data;
	backend->base.impl = &consolekit2_impl;

	check_pending_events(backend);
	return &backend->base;

error:
	destroy(backend);
	errno = -ret;
	return NULL;
}

const struct seat_impl consolekit2_impl = {
	.open_seat = consolekit2_open_seat,
	.disable_seat = disable_seat,
	.close_seat = close_seat,
	.seat_name = seat_name,
	.open_device = open_device,
	.close_device = close_device,
	.switch_session = switch_session,
	.get_fd = get_fd,
	.dispatch = dispatch_and_execute,
};
