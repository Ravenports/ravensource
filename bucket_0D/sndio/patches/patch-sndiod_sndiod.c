--- sndiod/sndiod.c.orig	2018-07-27 13:42:51 UTC
+++ sndiod/sndiod.c
@@ -19,7 +19,18 @@
 #include <sys/resource.h>
 #include <sys/socket.h>
 
+#ifdef __sun__
+#define errx(exitcode, format, args...) \
+	{ warnx(format, ## args); exit(exitcode); }
+#define warnx(format, args...) \
+	fprintf(stderr, format "\n", ## args)
+#define err(exitcode, format, args...) \
+	errx(exitcode, format ": %s", ## args, strerror(errno))
+#define warn(format, args...) \
+	warnx(format ": %s", ## args, strerror(errno))
+#else
 #include <err.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <grp.h>
@@ -505,12 +516,29 @@ main(int argc, char **argv)
 	if (background) {
 		log_flush();
 		log_level = 0;
+#ifdef __sun__
+		{
+			pid_t process_id = 0;
+			pid_t sid = 0;
+			process_id = fork();
+			if (process_id < 0) { err(1, "daemon"); }
+			if (process_id > 0) { exit(0); }
+			umask(0);
+			sid = setsid();
+			if (sid < 0) { err(1, "daemon-sid"); }
+			chdir("/");
+			close(STDIN_FILENO);
+			close(STDOUT_FILENO);
+			close(STDERR_FILENO);
+		}
+#else
 		if (daemon(0, 0) < 0)
 			err(1, "daemon");
+#endif
 	}
 	if (pw != NULL) {
 		if (setpriority(PRIO_PROCESS, 0, SNDIO_PRIO) < 0)
-			err(1, "setpriority");
+			warn("setpriority");
 		if (setgroups(1, &pw->pw_gid) ||
 		    setgid(pw->pw_gid) ||
 		    setuid(pw->pw_uid))
