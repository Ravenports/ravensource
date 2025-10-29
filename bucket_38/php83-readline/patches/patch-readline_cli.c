--- readline_cli.c.orig	2025-09-23 17:57:26 UTC
+++ readline_cli.c
@@ -19,6 +19,10 @@
 #include "config.h"
 #endif
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 
 #ifndef HAVE_RL_COMPLETION_MATCHES
