--- src/modules/module-netjack2-manager.c.orig	2025-07-23 15:42:58 UTC
+++ src/modules/module-netjack2-manager.c
@@ -39,6 +39,10 @@
 #include "module-netjack2/peer.c"
 #include "network-utils.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
 #ifndef IPTOS_DSCP
 #define IPTOS_DSCP_MASK 0xfc
 #define IPTOS_DSCP(x) ((x) & IPTOS_DSCP_MASK)
@@ -892,10 +896,16 @@ static int make_announce_socket(struct s
 		static const uint32_t ipv4_mcast_mask = 0xe0000000;
 		struct sockaddr_in *sa4 = (struct sockaddr_in*)sa;
 		if ((ntohl(sa4->sin_addr.s_addr) & ipv4_mcast_mask) == ipv4_mcast_mask) {
+#if defined(__NetBSD__)
+			struct ip_mreq mr4;
+			memset(&mr4, 0, sizeof(mr4));
+			mr4.imr_multiaddr = sa4->sin_addr;
+#else
 			struct ip_mreqn mr4;
 			memset(&mr4, 0, sizeof(mr4));
 			mr4.imr_multiaddr = sa4->sin_addr;
 			mr4.imr_ifindex = req.ifr_ifindex;
+#endif
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
 		} else {
 			sa4->sin_addr.s_addr = INADDR_ANY;
