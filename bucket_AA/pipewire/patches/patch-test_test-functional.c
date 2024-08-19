--- test/test-functional.c.orig	2024-07-31 10:02:24 UTC
+++ test/test-functional.c
@@ -4,6 +4,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "pwtest.h"
 
 PWTEST(openal_info_test)
