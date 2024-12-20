--- lib/librdkafka-2.4.0/src/snappy_compat.h.orig	2024-12-19 17:21:21 UTC
+++ lib/librdkafka-2.4.0/src/snappy_compat.h
@@ -33,7 +33,7 @@
 
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #elif defined(__APPLE_CC_) || (defined(__MACH__) && defined(__APPLE__))  /* MacOS/X support */
 #  include <machine/endian.h>
