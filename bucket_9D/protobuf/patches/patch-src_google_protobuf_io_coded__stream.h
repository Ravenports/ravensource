--- ../src/google/protobuf/io/coded_stream.h.orig	2021-03-04 21:35:04 UTC
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
