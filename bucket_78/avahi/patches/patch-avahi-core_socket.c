--- avahi-core/socket.c.orig	2020-02-18 06:51:47 UTC
+++ avahi-core/socket.c
@@ -542,7 +542,8 @@ int avahi_send_dns_packet_ipv4(
     }
 #elif defined(IP_MULTICAST_IF)
     if (src_address) {
-        struct in_addr any = { INADDR_ANY };
+        //struct in_addr any = { INADDR_ANY };
+	const uint32_t any = INADDR_ANY;
         if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, src_address ? &src_address->address : &any, sizeof(struct in_addr)) < 0) {
             avahi_log_warn("IP_MULTICAST_IF failed: %s", strerror(errno));
             return -1;
