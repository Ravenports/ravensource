--- src/tunnel.c.orig	2025-01-20 03:11:47 UTC
+++ src/tunnel.c
@@ -46,6 +46,10 @@
 #define SET_INTERFACE
 #endif
 
+#if defined(__sun__)
+#include <netinet/tcp.h>
+#endif
+
 #include <libcork/core.h>
 
 #include "netutils.h"
