--- lib/libpm.c.orig	2024-06-28 23:33:22 UTC
+++ lib/libpm.c
@@ -17,6 +17,7 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdarg.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <setjmp.h>
@@ -849,7 +850,7 @@ pm_arg0toprogname(const char arg0[]) {
 unsigned int
 pm_randseed(void) {
 
-    return time(NULL) ^ getpid();
+    return arc4random();
 
 }
 
