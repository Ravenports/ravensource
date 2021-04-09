--- ../src/google/protobuf/io/coded_stream.h.orig	2021-04-07 22:38:38 UTC
+++ ../src/google/protobuf/io/coded_stream.h
@@ -133,6 +133,10 @@
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
