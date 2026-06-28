--- tests/api.c.orig	2026-04-08 19:41:40 UTC
+++ tests/api.c
@@ -52,7 +52,7 @@
 
 #include <stdlib.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if 1
 #include <unistd.h>
 #include <sys/wait.h>
 #endif
