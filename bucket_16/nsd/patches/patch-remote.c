--- remote.c.orig	2026-02-24 09:02:38 UTC
+++ remote.c
@@ -103,6 +103,10 @@
 #define AF_LOCAL AF_UNIX
 #endif
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** number of seconds timeout on incoming remote control handshake */
 #define REMOTE_CONTROL_TCP_TIMEOUT 120
 
