--- lib/plat/unix/private-lib-plat-unix.h.orig	2025-11-29 19:42:32 UTC
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
