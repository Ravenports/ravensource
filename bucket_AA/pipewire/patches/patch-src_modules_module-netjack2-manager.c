--- src/modules/module-netjack2-manager.c.orig	2024-02-02 13:09:07 UTC
+++ src/modules/module-netjack2-manager.c
@@ -37,6 +37,10 @@
 
 #include "module-netjack2/peer.c"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
 #ifndef IPTOS_DSCP
 #define IPTOS_DSCP_MASK 0xfc
 #define IPTOS_DSCP(x) ((x) & IPTOS_DSCP_MASK)
