$NetBSD: patch-video_out_drm__common.c,v 1.4 2020/12/19 11:27:51 leot Exp $

Enable support for DRM on NetBSD.

--- video/out/drm_common.c.orig	2023-07-23 17:10:36 UTC
+++ video/out/drm_common.c
@@ -31,6 +31,9 @@
 
 #if HAVE_CONSIO_H
 #include <sys/consio.h>
+#elif HAVE_WSDISPLAY_USL_IO_H
+#include <sys/types.h>
+#include <dev/wscons/wsdisplay_usl_io.h>
 #else
 #include <sys/vt.h>
 #endif
