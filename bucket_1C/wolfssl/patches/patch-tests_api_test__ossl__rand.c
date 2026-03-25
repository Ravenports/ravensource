--- tests/api/test_ossl_rand.c.orig	2026-03-18 23:01:31 UTC
+++ tests/api/test_ossl_rand.c
@@ -21,7 +21,7 @@
 
 #include <tests/unit.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if 1
 #include <unistd.h>
 #include <sys/wait.h>
 #endif
