--- src/clients/spdsend/server.c.orig	2025-01-18 16:28:53 UTC
+++ src/clients/spdsend/server.c
@@ -32,6 +32,7 @@
 
 #include <errno.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #if USE_THREADS
