--- terms.c.orig	2023-01-21 02:01:52 UTC
+++ terms.c
@@ -28,7 +28,7 @@
 #endif				/* USE_GPM */
 #ifdef USE_SYSMOUSE
 #include <osreldate.h>
-#if (__FreeBSD_version >= 400017) || (__FreeBSD_kernel_version >= 400017)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__)
 #include <sys/consio.h>
 #include <sys/fbio.h>
 #else
