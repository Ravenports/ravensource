--- src/modules/module-rtp-source.c.orig	2024-02-02 13:09:07 UTC
+++ src/modules/module-rtp-source.c
@@ -31,7 +31,7 @@
 
 #include <module-rtp/stream.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define ifr_ifindex ifr_index
 #endif
 
