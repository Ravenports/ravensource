--- port/cpl_spawn.cpp.orig	2025-01-08 14:54:06 UTC
+++ port/cpl_spawn.cpp
@@ -41,7 +41,7 @@
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
 #else
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 extern __attribute__((__weak__)) char **environ;
 #else
 extern char **environ;
