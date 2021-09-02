--- common/discover.c.orig	2021-05-14 10:51:30 UTC
+++ common/discover.c
@@ -45,8 +45,8 @@ struct interface_info *fallback_interfac
 
 int interfaces_invalidated;
 int quiet_interface_discovery;
-u_int16_t local_port;
-u_int16_t remote_port;
+u_int16_t local_port = 0;
+u_int16_t remote_port = 0;
 u_int16_t relay_port = 0;
 int dhcpv4_over_dhcpv6 = 0;
 int (*dhcp_interface_setup_hook) (struct interface_info *, struct iaddr *);
