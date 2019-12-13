--- tools/build/src/engine/jam.h.orig	2019-12-10 00:20:17 UTC
+++ tools/build/src/engine/jam.h
@@ -297,7 +297,7 @@
     #define OSMINOR "OS=SINIX"
     #define OS_SINIX
 #endif
-#ifdef sun
+#ifdef __sun
     #if defined(__svr4__) || defined(__SVR4)
         #define OSMINOR "OS=SOLARIS"
         #define OS_SOLARIS
