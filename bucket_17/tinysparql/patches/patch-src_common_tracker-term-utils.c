--- src/common/tracker-term-utils.c.orig	2026-04-14 21:01:56 UTC
+++ src/common/tracker-term-utils.c
@@ -27,6 +27,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdio.h>
+#if defined(__sun)
+#include <sys/termios.h>
+#endif
 
 static GSubprocess *pager = NULL;
 static gint stdout_fd = 0;
