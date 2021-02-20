--- include/gssrpc/rpc.h.orig	2021-02-18 16:35:16 UTC
+++ include/gssrpc/rpc.h
@@ -39,6 +39,7 @@
 #ifndef GSSRPC_RPC_H
 #define GSSRPC_RPC_H
 
+#include <sys/socket.h>
 #include <gssrpc/types.h>		/* some typedefs */
 #include <netinet/in.h>
 
