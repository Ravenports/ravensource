--- zrcp/remote.c.orig	2025-09-25 16:14:00 UTC
+++ zrcp/remote.c
@@ -105,7 +105,7 @@ int zrcp_command_close_all_menus=0;
 	#include <arpa/inet.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 #include <netinet/in.h>
 #endif
 
