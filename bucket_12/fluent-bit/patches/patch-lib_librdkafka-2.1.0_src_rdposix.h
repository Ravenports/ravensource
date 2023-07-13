--- lib/librdkafka-2.1.0/src/rdposix.h.orig	2023-07-12 22:47:35 UTC
+++ lib/librdkafka-2.1.0/src/rdposix.h
@@ -65,7 +65,7 @@
 /**
  * Allocation
  */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 /* alloca(3) is in stdlib on FreeBSD */
 #include <alloca.h>
 #endif
