--- roms/u-boot/include/compiler.h.orig	2024-11-20 22:48:58 UTC
+++ roms/u-boot/include/compiler.h
@@ -14,6 +14,7 @@
     defined(__NetBSD__)  || \
     defined(__FreeBSD__) || \
     defined(__sun__)	 || \
+    defined(__DragonFly__) || \
     defined(__APPLE__)
 # include <inttypes.h>
 #elif defined(__linux__) || defined(__WIN32__) || defined(__MINGW32__) || defined(__OpenBSD__)
@@ -45,10 +46,10 @@
 #ifdef __linux__
 # include <endian.h>
 # include <byteswap.h>
-#elif defined(__MACH__) || defined(__FreeBSD__)
+#elif defined(__MACH__) || defined(__FreeBSD__) || defined(__DragonFly__)
 # include <machine/endian.h>
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 # include <sys/endian.h> /* htole32 and friends */
 # define __BYTE_ORDER BYTE_ORDER
 # define __LITTLE_ENDIAN LITTLE_ENDIAN
