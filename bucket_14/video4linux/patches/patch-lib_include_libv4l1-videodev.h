--- lib/include/libv4l1-videodev.h.orig	2013-06-28 20:10:56 UTC
+++ lib/include/libv4l1-videodev.h
@@ -6,9 +6,12 @@
 #include <linux/ioctl.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <sys/ioctl.h>
 #endif
+#if defined __sun__
+#include <sys/ioccom.h>
+#endif
 
 #include <stdint.h>
 
