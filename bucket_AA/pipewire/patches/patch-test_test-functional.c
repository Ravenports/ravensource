--- test/test-functional.c.orig	2025-05-22 08:59:37 UTC
+++ test/test-functional.c
@@ -6,6 +6,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "pwtest.h"
 
 PWTEST(openal_info_test)
