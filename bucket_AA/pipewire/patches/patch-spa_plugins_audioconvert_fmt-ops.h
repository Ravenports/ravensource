--- spa/plugins/audioconvert/fmt-ops.h.orig	2024-10-23 07:44:10 UTC
+++ spa/plugins/audioconvert/fmt-ops.h
@@ -3,7 +3,7 @@
 /* SPDX-License-Identifier: MIT */
 
 #include <math.h>
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #define bswap_16 bswap16
 #define bswap_32 bswap32
