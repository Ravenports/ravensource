--- tools/build/src/engine/jam.h.orig	2024-04-11 18:48:06 UTC
+++ tools/build/src/engine/jam.h
@@ -300,7 +300,7 @@
     #define OSMINOR "OS=SINIX"
     #define OS_SINIX
 #endif
-#ifdef sun
+#ifdef __sun
     #if defined(__svr4__) || defined(__SVR4)
         #define OSMINOR "OS=SOLARIS"
         #define OS_SOLARIS
