--- src/modules/module-netjack2/peer.c.orig	2024-10-23 07:44:10 UTC
+++ src/modules/module-netjack2/peer.c
@@ -1,5 +1,12 @@
 
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#else
 #include <byteswap.h>
+#endif
 
 #ifdef HAVE_OPUS_CUSTOM
 #include <opus/opus.h>
