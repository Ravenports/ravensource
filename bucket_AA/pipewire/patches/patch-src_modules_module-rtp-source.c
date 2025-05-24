--- src/modules/module-rtp-source.c.orig	2025-05-22 08:59:37 UTC
+++ src/modules/module-rtp-source.c
@@ -267,10 +267,16 @@ static int make_socket(const struct sock
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
 			pw_net_get_ip((struct sockaddr_storage*)sa, addr, sizeof(addr), NULL, NULL);
 			pw_log_info("join IPv4 group: %s", addr);
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
