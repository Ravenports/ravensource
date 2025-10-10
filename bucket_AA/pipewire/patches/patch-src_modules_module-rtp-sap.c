--- src/modules/module-rtp-sap.c.orig	2025-09-11 08:12:34 UTC
+++ src/modules/module-rtp-sap.c
@@ -32,6 +32,14 @@
 #define SO_PASSCRED LOCAL_CREDS_PERSISTENT
 #endif
 
+#if defined(__DragonFly__)
+#define ifr_ifindex ifr_index
+#endif
+
+#if defined(__MidnightBSD__)
+#include <sys/endian.h>
+#endif
+
 /** \page page_module_rtp_sap SAP Announce and create RTP streams
  *
  * The `rtp-sap` module announces RTP streams that match the rules with the
@@ -390,11 +398,13 @@ static int make_unix_socket(const char *
 		return -1;
 	}
 
+#if !defined(__MidnightBSD__) && !defined(__NetBSD__)
 	int val = 1;
 	if (setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &val, sizeof(val)) < 0) {
 		pw_log_warn("Failed to bind PTP management socket");
 		return -1;
 	}
+#endif
 
 	spa_zero(addr);
 	addr.sun_family = AF_UNIX;
@@ -487,10 +497,16 @@ static int make_recv_socket(struct socka
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
 			pw_net_get_ip(sa, addr, sizeof(addr), NULL, NULL);
 			pw_log_info("join IPv4 group: %s iface:%d", addr, req.ifr_ifindex);
 			res = setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr4, sizeof(mr4));
