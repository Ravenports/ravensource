--- test/test-functional.c.orig	2024-09-27 10:02:20 UTC
+++ test/test-functional.c
@@ -6,6 +6,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "pwtest.h"
 
 PWTEST(openal_info_test)
