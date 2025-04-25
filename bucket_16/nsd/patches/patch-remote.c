--- remote.c.orig	2025-04-24 08:28:28 UTC
+++ remote.c
@@ -102,6 +102,10 @@
 #define AF_LOCAL AF_UNIX
 #endif
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** number of seconds timeout on incoming remote control handshake */
 #define REMOTE_CONTROL_TCP_TIMEOUT 120
 
