--- readline_cli.c.orig	2019-02-05 13:10:04 UTC
+++ readline_cli.c
@@ -21,6 +21,10 @@
 #include "config.h"
 #endif
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 
 #ifndef HAVE_RL_COMPLETION_MATCHES
