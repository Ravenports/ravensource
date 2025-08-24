--- lib/librdkafka-2.10.1/src/snappy_compat.h.orig	2025-08-21 03:14:34 UTC
+++ lib/librdkafka-2.10.1/src/snappy_compat.h
@@ -33,7 +33,7 @@
 
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #elif defined(__APPLE_CC_) || (defined(__MACH__) && defined(__APPLE__))  /* MacOS/X support */
 #  include <machine/endian.h>
