--- src/mesa/main/compiler.h.orig	2018-12-13 14:02:21 UTC
+++ src/mesa/main/compiler.h
@@ -51,6 +51,9 @@
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE32( x )	bswap32( x )
 #elif defined(__APPLE__)
 #include <CoreFoundation/CFByteOrder.h>
 #define CPU_TO_LE32( x )	CFSwapInt32HostToLittle( x )
