--- newmgrep.c.orig	2016-10-22 12:40:44 UTC
+++ newmgrep.c
@@ -16,7 +16,7 @@
 #include <sys/types.h>
 #endif
 
-#if defined(_WIN32) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__)
     #include <sys/stat.h>
 #endif
 
