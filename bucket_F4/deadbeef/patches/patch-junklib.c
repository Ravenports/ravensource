--- junklib.c.orig	2019-06-23 19:51:04 UTC
+++ junklib.c
@@ -33,7 +33,6 @@
 #include <string.h>
 #if HAVE_ICONV
   #ifndef __MINGW32__
-  #define LIBICONV_PLUG
   #endif
   #include <iconv.h>
 #elif HAVE_ICU
