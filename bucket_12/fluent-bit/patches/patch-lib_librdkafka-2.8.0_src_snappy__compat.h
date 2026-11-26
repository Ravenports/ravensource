--- lib/librdkafka-2.15.0/src/snappy_compat.h.orig	2026-11-24 16:22:45 UTC
+++ lib/librdkafka-2.15.0/src/snappy_compat.h
@@ -33,7 +33,7 @@
 
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #elif defined(__APPLE_CC_) || (defined(__MACH__) && defined(__APPLE__))  /* MacOS/X support */
 #  include <machine/endian.h>
