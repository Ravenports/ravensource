--- src/inotify.c.orig	2025-01-04 11:05:30 UTC
+++ src/inotify.c
@@ -30,6 +30,9 @@ along with GNU Emacs.  If not, see <http
 
 #include <sys/inotify.h>
 #include <sys/ioctl.h>
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
 
 /* Ignore bits that might be undefined on old GNU/Linux systems.  */
 #ifndef IN_EXCL_UNLINK
