--- src/modules/module-netjack2-manager.c.orig	2024-09-27 10:02:20 UTC
+++ src/modules/module-netjack2-manager.c
@@ -38,6 +38,10 @@
 #include "module-netjack2/peer.c"
 #include "network-utils.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
 #ifndef IPTOS_DSCP
 #define IPTOS_DSCP_MASK 0xfc
 #define IPTOS_DSCP(x) ((x) & IPTOS_DSCP_MASK)
