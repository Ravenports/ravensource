--- lib/libpm.c.orig	2025-06-29 03:49:30 UTC
+++ lib/libpm.c
@@ -17,6 +17,7 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdarg.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <setjmp.h>
@@ -837,7 +838,7 @@ pm_arg0toprogname(const char arg0[]) {
 unsigned int
 pm_randseed(void) {
 
-    return time(NULL) ^ getpid();
+    return arc4random();
 
 }
 
