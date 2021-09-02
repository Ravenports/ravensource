--- relay/dhcrelay.c.orig	2021-05-14 13:07:09 UTC
+++ relay/dhcrelay.c
@@ -95,8 +95,8 @@ enum { forward_and_append,	/* Forward an
        forward_untouched,	/* Forward without changes. */
        discard } agent_relay_mode = forward_and_replace;
 
-u_int16_t local_port;
-u_int16_t remote_port;
+extern u_int16_t local_port;
+extern u_int16_t remote_port;
 
 /* Relay agent server list. */
 struct server_list {
