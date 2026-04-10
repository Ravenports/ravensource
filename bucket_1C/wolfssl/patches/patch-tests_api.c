--- tests/api.c.orig	2026-03-18 23:01:31.000000000 -0000
+++ tests/api.c
@@ -52,7 +52,7 @@
 
 #include <stdlib.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if 1
 #include <unistd.h>
 #include <sys/wait.h>
 #endif
