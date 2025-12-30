--- lib/librdkafka-2.10.1/src/rdendian.h.orig	2025-11-11 21:07:03 UTC
+++ lib/librdkafka-2.10.1/src/rdendian.h
@@ -40,7 +40,7 @@
  *   le64toh()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined __GLIBC__
 #include <endian.h>
