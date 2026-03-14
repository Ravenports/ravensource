--- lib/plat/unix/private-lib-plat-unix.h.orig	2025-12-03 06:15:09 UTC
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
