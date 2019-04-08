--- junklib.c.orig	2019-04-06 21:21:38 UTC
+++ junklib.c
@@ -32,7 +32,6 @@
 #include <stdlib.h>
 #include <string.h>
 #if HAVE_ICONV
-  #define LIBICONV_PLUG
   #include <iconv.h>
 #elif HAVE_ICU
   #warning icu
