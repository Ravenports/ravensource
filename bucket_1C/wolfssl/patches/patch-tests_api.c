--- tests/api.c.orig	2025-07-17 22:03:14 UTC
+++ tests/api.c
@@ -52,7 +52,7 @@
 
 #include <stdlib.h>
 
-#ifdef __linux__
+#if 1
 #include <unistd.h>
 #include <sys/wait.h>
 #endif
