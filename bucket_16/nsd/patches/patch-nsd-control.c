--- nsd-control.c.orig	2025-04-24 08:28:28 UTC
+++ nsd-control.c
@@ -96,6 +96,10 @@ static void ssl_path_err(const char* s,
 /** timeout to wait for connection over stream, in msec */
 #define NSD_CONTROL_CONNECT_TIMEOUT 5000
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** Give nsd-control usage, and exit (1). */
 static void
 usage()
