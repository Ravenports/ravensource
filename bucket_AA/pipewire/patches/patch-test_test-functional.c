--- test/test-functional.c.orig	2025-07-23 15:42:58 UTC
+++ test/test-functional.c
@@ -6,6 +6,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "pwtest.h"
 
 PWTEST(openal_info_test)
