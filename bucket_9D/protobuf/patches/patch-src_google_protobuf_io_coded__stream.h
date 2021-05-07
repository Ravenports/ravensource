--- ../src/google/protobuf/io/coded_stream.h.orig	2021-05-06 19:50:11 UTC
+++ ../src/google/protobuf/io/coded_stream.h
@@ -133,8 +133,10 @@
 #else
 #ifdef __APPLE__
 #include <machine/endian.h>  // __BYTE_ORDER
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>  // __BYTE_ORDER
+#elif defined(__sun__)
+#define __LITTLE_ENDIAN__
 #else
 #include <endian.h>  // __BYTE_ORDER
 #endif
