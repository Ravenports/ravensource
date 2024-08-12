--- src/clients/spdsend/server.c.orig	2023-06-05 22:03:00 UTC
+++ src/clients/spdsend/server.c
@@ -32,6 +32,7 @@
 
 #include <errno.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #if USE_THREADS
