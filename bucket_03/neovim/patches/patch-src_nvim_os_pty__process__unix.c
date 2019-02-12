--- src/nvim/os/pty_process_unix.c.orig	2019-01-13 13:25:08 UTC
+++ src/nvim/os/pty_process_unix.c
@@ -16,6 +16,78 @@
 # include <libutil.h>
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 # include <util.h>
+#elif defined __sun__
+#include <fcntl.h>
+#include <strings.h>
+#include <unistd.h>
+#include <stropts.h>
+#include <nvim/log.h>
+
+static int
+cfsetspeed(struct termios *t, speed_t speed) {
+   cfsetispeed(t, speed);
+   cfsetospeed(t, speed);
+   return (0);
+}
+
+static pid_t
+forkpty(int *master, char *name, struct termios *tio, struct winsize *ws)
+{
+	int	slave = -1;
+	char   *path;
+	pid_t	pid;
+
+	if ((*master = open("/dev/ptmx", O_RDWR|O_NOCTTY)) == -1)
+		return (-1);
+	if (grantpt(*master) != 0)
+		goto out;
+	if (unlockpt(*master) != 0)
+		goto out;
+
+	if ((path = ptsname(*master)) == NULL)
+		goto out;
+	if (name != NULL)
+		strlcpy(name, path, _SC_TTY_NAME_MAX);
+	if ((slave = open(path, O_RDWR|O_NOCTTY)) == -1)
+		goto out;
+
+	switch (pid = fork()) {
+	case -1:
+		goto out;
+	case 0:
+		close(*master);
+
+		setsid();
+		if (ioctl(slave, TIOCSCTTY, NULL) == -1)
+			ELOG("ioctl failed");
+		if (ioctl(slave, I_PUSH, "ptem") == -1)
+			ELOG("ioctl failed");
+		if (ioctl(slave, I_PUSH, "ldterm") == -1)
+			ELOG("ioctl failed");
+
+		if (tio != NULL && tcsetattr(slave, TCSAFLUSH, tio) == -1)
+			ELOG("tcsetattr failed");
+		if (ioctl(slave, TIOCSWINSZ, ws) == -1)
+			ELOG("ioctl failed");
+
+		dup2(slave, 0);
+		dup2(slave, 1);
+		dup2(slave, 2);
+		if (slave > 2)
+			close(slave);
+		return (0);
+	}
+
+	close(slave);
+	return (pid);
+
+out:
+	if (*master != -1)
+		close(*master);
+	if (slave != -1)
+		close(slave);
+	return (-1);
+}
 #else
 # include <pty.h>
 #endif
