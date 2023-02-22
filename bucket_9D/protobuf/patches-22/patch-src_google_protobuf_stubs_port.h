--- ../src/google/protobuf/stubs/port.h.orig	2023-02-16 17:13:25 UTC
+++ ../src/google/protobuf/stubs/port.h
@@ -61,12 +61,14 @@
 #else
 #ifdef __APPLE__
 #include <machine/endian.h>  // __BYTE_ORDER
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>  // __BYTE_ORDER
 #elif (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
 #include <sys/isa_defs.h>  // __BYTE_ORDER
 #elif defined(_AIX) || defined(__TOS_AIX__)
 #include <sys/machine.h>  // BYTE_ORDER
+#elif defined(__sun__)
+#define __LITTLE_ENDIAN__
 #elif defined(__QNX__)
 #include <sys/param.h>  // BYTE_ORDER
 #else
@@ -84,6 +86,8 @@
 #ifdef _MSC_VER
 #include <stdlib.h>  // NOLINT(build/include)
 #include <intrin.h>
+#elif defined(__sun__)
+#include <sys/byteorder.h>
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
 #elif defined(__linux__) || defined(__ANDROID__) || defined(__CYGWIN__)
@@ -190,6 +194,11 @@ inline void GOOGLE_UNALIGNED_STORE64(voi
 #define bswap_32(x) _byteswap_ulong(x)
 #define bswap_64(x) _byteswap_uint64(x)
 
+#elif defined(__sun__)
+#define bswap_16(x) BSWAP_16(x)
+#define bswap_32(x) BSWAP_32(x)
+#define bswap_64(x) BSWAP_64(x)
+
 #elif defined(__APPLE__)
 // Mac OS X / Darwin features
 #define bswap_16(x) OSSwapInt16(x)
