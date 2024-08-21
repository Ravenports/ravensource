--- zrcp/remote.c.orig	2024-06-06 15:45:53 UTC
+++ zrcp/remote.c
@@ -104,7 +104,7 @@ int zrcp_command_close_all_menus=0;
 	#include <arpa/inet.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #include <netinet/in.h>
 #endif
 
