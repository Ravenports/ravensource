--- source/spawn/posix_const.c.orig	2025-01-28 16:38:20 UTC
+++ source/spawn/posix_const.c
@@ -3,6 +3,10 @@
 #include <poll.h>
 #include <sys/ioctl.h>
 #include <sys/wait.h>
+#if defined(__sun__)
+#include <unistd.h>
+#include <sys/termios.h>
+#endif
 
 #ifndef O_CLOEXEC
 /* There is no such constant on RHES 5 and earlier */
