No libbbsd on solaris, so add support for err.h
err=>warn: Make sure sndiod can be started inside jails as root

--- sndiod/sndiod.c.orig	2024-08-01 15:36:54 UTC
+++ sndiod/sndiod.c
@@ -19,7 +19,11 @@
 #include <sys/resource.h>
 #include <sys/socket.h>
 
+#if defined(__sun)
+#include <stdarg.h>
+#else
 #include <err.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <grp.h>
@@ -85,6 +89,37 @@
 #define DEFAULT_BITS	16
 #endif
 
+#if defined(__sun)
+/* warn: prints message + errno string, does NOT exit */
+static void warn(const char *fmt, ...) {
+    va_list ap;
+    va_start(ap, fmt);
+    vfprintf(stderr, fmt, ap);
+    fprintf(stderr, ": %s\n", strerror(errno));
+    va_end(ap);
+}
+
+/* errx: prints message, does NOT print errno, EXITS */
+static void errx(int eval, const char *fmt, ...) {
+    va_list ap;
+    va_start(ap, fmt);
+    vfprintf(stderr, fmt, ap);
+    fprintf(stderr, "\n");
+    va_end(ap);
+    exit(eval);
+}
+
+/* keeping err here just in case you still need it */
+static void err(int eval, const char *fmt, ...) {
+    va_list ap;
+    va_start(ap, fmt);
+    vfprintf(stderr, fmt, ap);
+    fprintf(stderr, ": %s\n", strerror(errno));
+    va_end(ap);
+    exit(eval);
+}
+#endif
+
 void sigint(int);
 void sighup(int);
 void opt_ch(int *, int *);
@@ -691,7 +726,7 @@ main(int argc, char **argv)
 	}
 	if (pw != NULL) {
 		if (setpriority(PRIO_PROCESS, 0, SNDIO_PRIO) == -1)
-			err(1, "setpriority");
+			warn("setpriority");
 		if (setgroups(1, &pw->pw_gid) == -1 ||
 		    setgid(pw->pw_gid) == -1 ||
 		    setuid(pw->pw_uid) == -1)
