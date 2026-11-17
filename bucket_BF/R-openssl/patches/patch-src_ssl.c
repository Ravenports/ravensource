--- src/ssl.c.orig	2025-01-07 23:50:42 UTC
+++ src/ssl.c
@@ -15,6 +15,11 @@
 #endif
 #endif
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#include <sys/endian.h>
+#endif
+
 #include <Rinternals.h>
 #include <stdlib.h>
 #include <string.h>
