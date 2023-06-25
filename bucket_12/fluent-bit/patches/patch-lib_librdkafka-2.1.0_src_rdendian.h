--- lib/librdkafka-2.1.0/src/rdendian.h.orig	2023-06-23 05:02:50 UTC
+++ lib/librdkafka-2.1.0/src/rdendian.h
@@ -40,7 +40,7 @@
  *   le64toh()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined __GLIBC__
 #include <endian.h>
