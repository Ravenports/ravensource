--- contrib/freebsd/include/linux/videodev2.h.orig	2015-05-06 19:24:59 UTC
+++ contrib/freebsd/include/linux/videodev2.h
@@ -60,6 +60,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 
 #ifndef HAVE_LINUX_INTEGER_TYPES
 /* XXX remove when depending software has been updated */
