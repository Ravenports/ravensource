--- src/modules/module-vban-recv.c.orig	2025-07-23 15:42:58 UTC
+++ src/modules/module-vban-recv.c
@@ -241,10 +241,16 @@ static int make_socket(const struct sock
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
