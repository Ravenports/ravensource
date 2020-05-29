--- tools/build/src/engine/jam.h.orig	2020-04-22 13:36:26 UTC
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
