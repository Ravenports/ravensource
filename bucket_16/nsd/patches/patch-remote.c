--- remote.c.orig	2023-12-06 09:06:53 UTC
+++ remote.c
@@ -97,6 +97,10 @@
 #define AF_LOCAL AF_UNIX
 #endif
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** number of seconds timeout on incoming remote control handshake */
 #define REMOTE_CONTROL_TCP_TIMEOUT 120
 
