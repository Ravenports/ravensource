--- lib/plat/unix/private-lib-plat-unix.h.orig	2025-07-12 14:25:04 UTC
+++ lib/plat/unix/private-lib-plat-unix.h
@@ -53,7 +53,7 @@
 #if defined(__APPLE__)
 #include <machine/endian.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #endif
 #if defined(__linux__)
