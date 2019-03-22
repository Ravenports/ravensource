--- src/wayland-server.c.orig	2019-03-21 00:55:25 UTC
+++ src/wayland-server.c
@@ -43,6 +43,13 @@
 #include <sys/file.h>
 #include <sys/stat.h>
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_UCRED_H
+#include <sys/types.h>
+#include <sys/ucred.h>
+#endif
+
 #include "wayland-util.h"
 #include "wayland-private.h"
 #include "wayland-server.h"
@@ -77,7 +84,11 @@ struct wl_client {
 	struct wl_list link;
 	struct wl_map objects;
 	struct wl_priv_signal destroy_signal;
+#ifdef HAVE_SYS_UCRED_H
+	struct xucred xucred;
+#else
 	struct ucred ucred;
+#endif
 	int error;
 	struct wl_priv_signal resource_created_signal;
 };
@@ -312,7 +323,11 @@ wl_resource_post_error(struct wl_resourc
 static void
 destroy_client_with_error(struct wl_client *client, const char *reason)
 {
+#ifdef HAVE_SYS_UCRED_H
+	wl_log("%s (uid %u)\n", reason, client->xucred.cr_uid);
+#else
 	wl_log("%s (pid %u)\n", reason, client->ucred.pid);
+#endif
 	wl_client_destroy(client);
 }
 
@@ -511,7 +526,9 @@ WL_EXPORT struct wl_client *
 wl_client_create(struct wl_display *display, int fd)
 {
 	struct wl_client *client;
+#ifndef HAVE_SYS_UCRED_H
 	socklen_t len;
+#endif
 
 	client = zalloc(sizeof *client);
 	if (client == NULL)
@@ -526,10 +543,12 @@ wl_client_create(struct wl_display *disp
 	if (!client->source)
 		goto err_client;
 
+#ifndef HAVE_SYS_UCRED_H
 	len = sizeof client->ucred;
 	if (getsockopt(fd, SOL_SOCKET, SO_PEERCRED,
 		       &client->ucred, &len) < 0)
 		goto err_source;
+#endif
 
 	client->connection = wl_connection_create(fd);
 	if (client->connection == NULL)
@@ -583,12 +602,21 @@ WL_EXPORT void
 wl_client_get_credentials(struct wl_client *client,
 			  pid_t *pid, uid_t *uid, gid_t *gid)
 {
+#ifdef HAVE_SYS_UCRED_H
+	if (pid)
+		*pid = 0;
+	if (uid)
+		*uid = client->xucred.cr_uid;
+	if (gid)
+		*gid = client->xucred.cr_gid;
+#else
 	if (pid)
 		*pid = client->ucred.pid;
 	if (uid)
 		*uid = client->ucred.uid;
 	if (gid)
 		*gid = client->ucred.gid;
+#endif
 }
 
 /** Get the file descriptor for the client
@@ -1362,7 +1390,7 @@ socket_data(int fd, uint32_t mask, void
 	client_fd = wl_os_accept_cloexec(fd, (struct sockaddr *) &name,
 					 &length);
 	if (client_fd < 0)
-		wl_log("failed to accept: %m\n");
+		wl_log("failed to accept: %s\n", strerror(errno));
 	else
 		if (!wl_client_create(display, client_fd))
 			close(client_fd);
@@ -1467,12 +1495,12 @@ _wl_display_add_socket(struct wl_display
 
 	size = offsetof (struct sockaddr_un, sun_path) + strlen(s->addr.sun_path);
 	if (bind(s->fd, (struct sockaddr *) &s->addr, size) < 0) {
-		wl_log("bind() failed with error: %m\n");
+		wl_log("bind() failed with error: %s\n", strerror(errno));
 		return -1;
 	}
 
 	if (listen(s->fd, 128) < 0) {
-		wl_log("listen() failed with error: %m\n");
+		wl_log("listen() failed with error: %s\n", strerror(errno));
 		return -1;
 	}
 
