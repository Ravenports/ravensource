--- lib/librdkafka-2.15.0/src/rdendian.h.orig	2026-11-24 16:22:45 UTC
+++ lib/librdkafka-2.15.0/src/rdendian.h
@@ -40,7 +40,7 @@
  *   le64toh()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined __GLIBC__
 #include <endian.h>
