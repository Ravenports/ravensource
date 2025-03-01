--- examples/client/client.c.orig	2025-02-20 20:31:48 UTC
+++ examples/client/client.c
@@ -22,6 +22,8 @@
     #include <config.h>
 #endif
 
+#include <signal.h>
+
 #define WOLFSSH_TEST_CLIENT
 
 #ifdef WOLFSSL_USER_SETTINGS
