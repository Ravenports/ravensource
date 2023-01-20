--- src/sna/sna_video.c.orig	2021-01-15 20:59:05 UTC
+++ src/sna/sna_video.c
@@ -59,7 +59,7 @@
 #include "intel_options.h"
 
 #include <xf86xv.h>
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <sys/endian.h>
 #ifdef __OpenBSD__
@@ -67,6 +67,9 @@
 #else
 #define bswap_32 bswap32
 #endif
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_32 BSWAP_32
 #else
 #include <byteswap.h>
 #endif
