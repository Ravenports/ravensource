--- lib/librdkafka-2.4.0/src/rdposix.h.orig	2025-03-24 22:35:10 UTC
+++ lib/librdkafka-2.4.0/src/rdposix.h
@@ -65,12 +65,12 @@
 /**
  * Allocation
  */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 /* alloca(3) is in stdlib on FreeBSD */
 #include <alloca.h>
 #endif
 
-#define rd_alloca(N) alloca(N)
+#define rd_alloca(N) __builtin_alloca(N)
 
 
 /**
