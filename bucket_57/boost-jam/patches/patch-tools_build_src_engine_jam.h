--- tools/build/src/engine/jam.h.orig	2021-04-13 16:23:21 UTC
+++ tools/build/src/engine/jam.h
@@ -304,7 +304,7 @@
     #define OSMINOR "OS=SINIX"
     #define OS_SINIX
 #endif
-#ifdef sun
+#ifdef __sun
     #if defined(__svr4__) || defined(__SVR4)
         #define OSMINOR "OS=SOLARIS"
         #define OS_SOLARIS
