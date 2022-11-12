--- remote.c.orig	2022-11-10 08:11:36 UTC
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
 
