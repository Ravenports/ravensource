--- include/gssrpc/rpc.h.orig	2019-01-08 16:02:37 UTC
+++ include/gssrpc/rpc.h
@@ -39,6 +39,7 @@
 #ifndef GSSRPC_RPC_H
 #define GSSRPC_RPC_H
 
+#include <sys/socket.h>
 #include <gssrpc/types.h>		/* some typedefs */
 #include <netinet/in.h>
 
