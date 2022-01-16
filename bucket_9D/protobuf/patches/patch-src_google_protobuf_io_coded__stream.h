--- ../src/google/protobuf/io/coded_stream.h.orig	2022-01-11 02:08:15 UTC
+++ ../src/google/protobuf/io/coded_stream.h
@@ -134,12 +134,14 @@
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
 #else
 #if !defined(__QNX__)
 #include <endian.h>  // __BYTE_ORDER
