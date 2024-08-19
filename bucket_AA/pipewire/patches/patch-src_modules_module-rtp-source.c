--- src/modules/module-rtp-source.c.orig	2024-07-31 10:02:24 UTC
+++ src/modules/module-rtp-source.c
@@ -32,7 +32,7 @@
 #include <module-rtp/stream.h>
 #include "network-utils.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define ifr_ifindex ifr_index
 #endif
 
