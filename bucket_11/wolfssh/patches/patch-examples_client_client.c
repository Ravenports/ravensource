--- examples/client/client.c.orig	2024-07-22 16:39:54 UTC
+++ examples/client/client.c
@@ -22,6 +22,8 @@
     #include <config.h>
 #endif
 
+#include <signal.h>
+
 #define WOLFSSH_TEST_CLIENT
 
 #ifdef WOLFSSL_USER_SETTINGS
