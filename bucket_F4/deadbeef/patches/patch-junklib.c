--- junklib.c.orig	2020-06-28 13:41:28 UTC
+++ junklib.c
@@ -33,7 +33,6 @@
 #include <string.h>
 #if HAVE_ICONV
   #ifndef __MINGW32__
-  #define LIBICONV_PLUG
   #endif
   #include <iconv.h>
 #elif HAVE_ICU
