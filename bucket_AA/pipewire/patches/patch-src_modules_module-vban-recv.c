--- src/modules/module-vban-recv.c.orig	2024-07-31 10:02:24 UTC
+++ src/modules/module-vban-recv.c
@@ -32,7 +32,7 @@
 #include <module-vban/stream.h>
 #include "network-utils.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define ifr_ifindex ifr_index
 #endif
 
