--- src/google/protobuf/stubs/port.h.orig	2025-05-28 16:52:59 UTC
+++ src/google/protobuf/stubs/port.h
@@ -25,6 +25,8 @@
 #ifdef _MSC_VER
 #include <stdlib.h>  // NOLINT(build/include)
 #include <intrin.h>
+#elif defined(__sun__)
+#include <sys/byteorder.h>
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
 #elif defined(__linux__) || defined(__ANDROID__) || defined(__CYGWIN__)
@@ -137,6 +139,11 @@ inline void GOOGLE_UNALIGNED_STORE64(voi
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
