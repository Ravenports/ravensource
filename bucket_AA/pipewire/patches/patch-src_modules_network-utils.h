--- src/modules/network-utils.h.orig	2025-07-23 15:42:58 UTC
+++ src/modules/network-utils.h
@@ -8,7 +8,7 @@
 #include <net/if.h>
 #include <errno.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define ifr_ifindex ifr_index
 #endif
 
