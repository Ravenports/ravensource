--- video/out/drm_common.c.orig	2024-09-23 17:36:41 UTC
+++ video/out/drm_common.c
@@ -34,6 +34,7 @@
 #elif HAVE_VT_H
 #include <sys/vt.h>
 #elif HAVE_WSDISPLAY_USL_IO_H
+#include <sys/types.h>
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif
 
