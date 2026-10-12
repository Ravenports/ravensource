--- examples/client/client.c.orig	2026-10-05 17:53:17 UTC
+++ examples/client/client.c
@@ -22,6 +22,8 @@
     #include <config.h>
 #endif
 
+#include <signal.h>
+
 #define WOLFSSH_TEST_CLIENT
 
 #ifdef WOLFSSL_USER_SETTINGS
