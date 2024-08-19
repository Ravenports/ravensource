--- src/modules/module-netjack2/peer.c.orig	2024-07-31 10:02:24 UTC
+++ src/modules/module-netjack2/peer.c
@@ -1,5 +1,12 @@
 
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#else
 #include <byteswap.h>
+#endif
 
 #ifdef HAVE_OPUS_CUSTOM
 #include <opus/opus.h>
