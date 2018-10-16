--- lib/driver/FreeBSD/freebsd.h.orig	2017-12-22 03:03:12 UTC
+++ lib/driver/FreeBSD/freebsd.h
@@ -80,6 +80,7 @@ struct ioc_read_audio
 #include <sys/ioctl.h>
 #include <sys/param.h> /* for __FreeBSD_version */
 
+#ifdef __FreeBSD__
 #if (__FreeBSD_version < 500000) && (__FreeBSD_kernel_version < 500000)
 #define DEVICE_POSTFIX "c"
 #else
@@ -87,6 +88,9 @@ struct ioc_read_audio
 #endif
 
 #define HAVE_FREEBSD_CAM
+#else
+#define DEVICE_POSTFIX "c"
+#endif
 #ifdef HAVE_FREEBSD_CAM
 #include <camlib.h>
 
