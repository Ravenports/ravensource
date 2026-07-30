--- src/rspamd.c.orig	2026-07-21 17:53:03 UTC
+++ src/rspamd.c
@@ -476,7 +476,7 @@ systemd_get_socket(struct rspamd_main *r
 	union {
 		struct sockaddr_storage ss;
 		struct sockaddr sa;
-		struct sockaddr_un sun;
+		struct sockaddr_un xun;
 		struct sockaddr_in6 s6;
 	} addr_storage;
 	socklen_t slen = sizeof(addr_storage);
