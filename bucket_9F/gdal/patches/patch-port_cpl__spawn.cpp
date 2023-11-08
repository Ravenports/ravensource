--- port/cpl_spawn.cpp.orig	2023-09-05 09:06:01 UTC
+++ port/cpl_spawn.cpp
@@ -57,7 +57,7 @@
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
 #else
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 extern __attribute__((__weak__)) char **environ;
 #else
 extern char **environ;
