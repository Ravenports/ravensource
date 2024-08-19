--- src/modules/module-netjack2-manager.c.orig	2024-07-31 10:02:24 UTC
+++ src/modules/module-netjack2-manager.c
@@ -42,6 +42,10 @@
 #define ifr_ifindex ifr_index
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
 #ifndef IPTOS_DSCP
 #define IPTOS_DSCP_MASK 0xfc
 #define IPTOS_DSCP(x) ((x) & IPTOS_DSCP_MASK)
