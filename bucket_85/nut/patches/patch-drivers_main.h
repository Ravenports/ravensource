--- drivers/main.h.orig	2026-04-01 14:18:21 UTC
+++ drivers/main.h
@@ -1,6 +1,7 @@
 #ifndef NUT_MAIN_H_SEEN
 #define NUT_MAIN_H_SEEN 1
 
+#include <sys/param.h>
 #include "common.h"
 #include "upsconf.h"
 #include "upshandler.h"
