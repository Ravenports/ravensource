--- st.c.orig	2025-08-09 13:00:58 UTC
+++ st.c
@@ -26,6 +26,9 @@
  #include <util.h>
 #elif defined(__FreeBSD__) || defined(__DragonFly__)
  #include <libutil.h>
+#elif defined(__sun)
+#include <stropts.h>
+#include <sys/termios.h>
 #endif
 
 /* Arbitrary sizes */
@@ -776,9 +779,20 @@ ttynew(const char *line, char *cmd, cons
 		return cmdfd;
 	}
 
+#if defined(__sun)
+	if ((m = posix_openpt(O_RDWR | O_NOCTTY)) < 0)
+		die("out of pty devices\n");
+	grantpt(m);
+	unlockpt(m);
+	if ((s = open(ptsname(m), O_RDWR | O_NOCTTY)) < 0)
+		die("can't open slave pty\n");
+	ioctl(s, I_PUSH, "ptem");
+	ioctl(s, I_PUSH, "ldterm");
+#else
 	/* seems to work fine on linux, openbsd and freebsd */
 	if (openpty(&m, &s, NULL, NULL, NULL) < 0)
 		die("openpty failed: %s\n", strerror(errno));
+#endif
 
 	switch (pid = fork()) {
 	case -1:
@@ -791,8 +805,10 @@ ttynew(const char *line, char *cmd, cons
 		dup2(s, 0);
 		dup2(s, 1);
 		dup2(s, 2);
+#if !defined(__sun)
 		if (ioctl(s, TIOCSCTTY, NULL) < 0)
 			die("ioctl TIOCSCTTY failed: %s\n", strerror(errno));
+#endif
 		if (s > 2)
 			close(s);
 #ifdef __OpenBSD__
