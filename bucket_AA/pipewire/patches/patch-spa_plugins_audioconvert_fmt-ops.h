--- spa/plugins/audioconvert/fmt-ops.h.orig	2024-07-31 10:02:24 UTC
+++ spa/plugins/audioconvert/fmt-ops.h
@@ -3,7 +3,7 @@
 /* SPDX-License-Identifier: MIT */
 
 #include <math.h>
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #define bswap_16 bswap16
 #define bswap_32 bswap32
