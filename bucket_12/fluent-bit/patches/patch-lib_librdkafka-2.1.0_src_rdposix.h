--- lib/librdkafka-2.3.0/src/rdposix.h.orig	2024-05-23 21:56:33 UTC
+++ lib/librdkafka-2.3.0/src/rdposix.h
@@ -65,7 +65,7 @@
 /**
  * Allocation
  */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 /* alloca(3) is in stdlib on FreeBSD */
 #include <alloca.h>
 #endif
