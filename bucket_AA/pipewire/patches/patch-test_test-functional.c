--- test/test-functional.c.orig	2025-09-11 08:12:34 UTC
+++ test/test-functional.c
@@ -6,6 +6,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "pwtest.h"
 
 PWTEST(openal_info_test)
