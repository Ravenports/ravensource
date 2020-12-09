--- remote.c.orig	2020-12-01 12:25:39 UTC
+++ remote.c
@@ -92,6 +92,10 @@
 #  include <sys/un.h>
 #endif
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** number of seconds timeout on incoming remote control handshake */
 #define REMOTE_CONTROL_TCP_TIMEOUT 120
 
