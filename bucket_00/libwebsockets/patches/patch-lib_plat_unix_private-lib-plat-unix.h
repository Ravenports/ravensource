--- lib/plat/unix/private-lib-plat-unix.h.orig	2026-03-17 16:35:25 UTC
+++ lib/plat/unix/private-lib-plat-unix.h
@@ -54,7 +54,7 @@
 #if defined(__APPLE__)
 #include <machine/endian.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #endif
 #if defined(__linux__)
