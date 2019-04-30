--- tools-for-build/grovel-headers.c.orig	2019-04-29 18:39:01 UTC
+++ tools-for-build/grovel-headers.c
@@ -42,7 +42,7 @@
 #ifdef LISP_FEATURE_ANDROID
   #include <termios.h>
 #else
-  #include <sys/termios.h>
+  #include <termios.h>
   #include <langinfo.h>
 #endif
   #include <sys/time.h>
