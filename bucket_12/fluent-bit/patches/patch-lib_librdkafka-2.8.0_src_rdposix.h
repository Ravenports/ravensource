--- lib/librdkafka-2.10.1/src/rdposix.h.orig	2025-10-08 13:42:21 UTC
+++ lib/librdkafka-2.10.1/src/rdposix.h
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
