--- lib/isc/netmgr/udp.c.orig	2026-11-06 10:59:36 UTC
+++ lib/isc/netmgr/udp.c
@@ -322,10 +322,16 @@ route_socket(uv_os_sock_t *fdp) {
 	(void)setsockopt(fd, PF_ROUTE, RO_MSGFILTER, &msgtypes,
 			 sizeof(msgtypes));
 #elif defined(ROUTE_MSGFILTER)
+#if defined(RTM_DESYNC)
 	/* OpenBSD */
 	unsigned int rtfilter = ROUTE_FILTER(RTM_NEWADDR) |
 				ROUTE_FILTER(RTM_DELADDR) |
 				ROUTE_FILTER(RTM_DESYNC);
+#else
+	/* DragonFly, FreeBSD */
+	unsigned int rtfilter = ROUTE_FILTER(RTM_NEWADDR) |
+				ROUTE_FILTER(RTM_DELADDR);
+#endif
 
 	(void)setsockopt(fd, AF_ROUTE, ROUTE_MSGFILTER, &rtfilter,
 			 sizeof(rtfilter));
