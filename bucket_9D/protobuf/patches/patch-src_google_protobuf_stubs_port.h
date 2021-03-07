--- ../src/google/protobuf/stubs/port.h.orig	2021-03-04 21:35:04 UTC
+++ ../src/google/protobuf/stubs/port.h
@@ -59,6 +59,10 @@
 #else
 #ifdef __APPLE__
 #include <machine/endian.h>  // __BYTE_ORDER
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+#include <sys/endian.h>
+#elif defined(__sun__)
+#define __LITTLE_ENDIAN__
 #else
 #include <endian.h>  // __BYTE_ORDER
 #endif
@@ -76,6 +80,8 @@
 #include <intrin.h>
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
+#elif defined(__sun__)
+#include <sys/byteorder.h>
 #elif defined(__GLIBC__) || defined(__BIONIC__) || defined(__CYGWIN__)
 #include <byteswap.h>  // IWYU pragma: export
 #endif
@@ -240,6 +246,11 @@ inline void GOOGLE_UNALIGNED_STORE64(voi
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
 
+#elif defined(__sun__)
+#define bswap_16(x) BSWAP_16(x)
+#define bswap_32(x) BSWAP_32(x)
+#define bswap_64(x) BSWAP_64(x)
+
 #elif !defined(__GLIBC__) && !defined(__BIONIC__) && !defined(__CYGWIN__)
 
 #ifndef bswap_16
