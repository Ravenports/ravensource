--- remote.c.orig	2020-04-16 08:09:33 UTC
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
 
