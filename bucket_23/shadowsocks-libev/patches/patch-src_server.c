--- src/server.c.orig	2025-01-20 03:11:47 UTC
+++ src/server.c
@@ -51,6 +51,10 @@
 #define SET_INTERFACE
 #endif
 
+#if defined(__sun__)
+#include <netinet/tcp.h>
+#endif
+
 #ifdef USE_NFTABLES
 #include <ctype.h>
 #include <linux/netfilter.h>
