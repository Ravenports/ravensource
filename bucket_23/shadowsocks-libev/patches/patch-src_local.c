--- src/local.c.orig	2026-02-09 01:15:12 UTC
+++ src/local.c
@@ -39,6 +39,9 @@
 #include <netdb.h>
 #include <netinet/in.h>
 #endif
+#if defined(__sun)
+#include <netinet/tcp.h>
+#endif
 #ifdef LIB_ONLY
 #include "shadowsocks.h"
 #endif
