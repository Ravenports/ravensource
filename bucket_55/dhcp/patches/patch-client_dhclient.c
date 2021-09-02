--- client/dhclient.c.orig	2021-05-14 13:06:48 UTC
+++ client/dhclient.c
@@ -83,8 +83,8 @@ static const char message [] = "Internet
 static const char url [] = "For info, please visit https://www.isc.org/software/dhcp/";
 #endif /* UNIT_TEST */
 
-u_int16_t local_port = 0;
-u_int16_t remote_port = 0;
+extern u_int16_t local_port;
+extern u_int16_t remote_port;
 #if defined(DHCPv6) && defined(DHCP4o6)
 int dhcp4o6_state = -1; /* -1 = stopped, 0 = polling, 1 = started */
 #endif
