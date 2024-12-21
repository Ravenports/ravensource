--- src/rspamd.c.orig	2024-12-16 14:04:14 UTC
+++ src/rspamd.c
@@ -56,8 +56,8 @@
 
 #ifdef WITH_HYPERSCAN
 #include "libserver/hyperscan_tools.h"
-#include "rspamd_simdutf.h"
 #endif
+#include "rspamd_simdutf.h"
 
 /* 2 seconds to fork new process in place of dead one */
 #define SOFT_FORK_TIME 2
