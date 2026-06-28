--- tests/api/test_ossl_rand.c.orig	2026-04-08 19:41:40 UTC
+++ tests/api/test_ossl_rand.c
@@ -21,7 +21,7 @@
 
 #include <tests/unit.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if 1
 #include <unistd.h>
 #include <sys/wait.h>
 #endif
