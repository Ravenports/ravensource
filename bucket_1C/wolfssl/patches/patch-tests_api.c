--- tests/api.c.orig	2026-09-25 20:18:05 UTC
+++ tests/api.c
@@ -55,7 +55,7 @@
 
 #include <stdlib.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if 1
 #include <unistd.h>
 #include <sys/wait.h>
 #endif
