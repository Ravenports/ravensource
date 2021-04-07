--- remote.c.orig	2021-04-06 11:23:15 UTC
+++ remote.c
@@ -95,6 +95,10 @@
 #define AF_LOCAL AF_UNIX
 #endif
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** number of seconds timeout on incoming remote control handshake */
 #define REMOTE_CONTROL_TCP_TIMEOUT 120
 
