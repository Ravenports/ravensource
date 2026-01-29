--- terms.c.orig	2025-08-20 09:32:27 UTC
+++ terms.c
@@ -29,7 +29,7 @@
 #ifdef USE_SYSMOUSE
 static int is_xterm = 0;
 #include <osreldate.h>
-#if (__FreeBSD_version >= 400017) || (__FreeBSD_kernel_version >= 400017)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__)
 #include <sys/consio.h>
 #include <sys/fbio.h>
 #else
