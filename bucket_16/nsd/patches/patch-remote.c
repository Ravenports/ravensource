--- remote.c.orig	2019-06-11 12:15:24 UTC
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
 
