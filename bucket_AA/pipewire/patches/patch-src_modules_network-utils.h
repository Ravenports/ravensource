--- src/modules/network-utils.h.orig	2024-10-23 07:44:10 UTC
+++ src/modules/network-utils.h
@@ -8,7 +8,7 @@
 #include <net/if.h>
 #include <errno.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define ifr_ifindex ifr_index
 #endif
 
