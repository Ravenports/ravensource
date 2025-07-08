--- p11-kit/rpc-server.c.orig	2024-07-01 13:53:16 UTC
+++ p11-kit/rpc-server.c
@@ -57,6 +57,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 #include <unistd.h>
 
 #ifdef ENABLE_NLS
