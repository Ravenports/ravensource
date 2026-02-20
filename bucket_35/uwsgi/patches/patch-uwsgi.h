$NetBSD: patch-uwsgi.h,v 1.11 2023/08/01 12:33:17 adam Exp $

Avoid using "sun" which breaks on SunOS
https://github.com/unbit/uwsgi/pull/2506

--- uwsgi.h.orig	2025-10-11 19:15:54 UTC
+++ uwsgi.h
@@ -1648,7 +1648,7 @@ struct wsgi_request {
 	union address {
 		struct sockaddr_in sin;
 		struct sockaddr_in6 sin6;
-		struct sockaddr_un sun;
+		struct sockaddr_un so_sun;
 	} client_addr;
 
 	uint8_t websocket_is_fin;
