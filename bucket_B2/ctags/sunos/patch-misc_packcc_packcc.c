--- misc/packcc/packcc.c.orig	Thu Sep 19 00:52:42 2019
+++ misc/packcc/packcc.c	Thu Sep 19 01:33:03 2019
@@ -50,17 +50,13 @@
 #include <assert.h>
 #include <stdbool.h>
 
-#ifndef _MSC_VER
-#if ((defined USE_SYSTEM_STRNLEN) == 0) && defined __GNUC__ && defined _WIN32 /* MinGW */
+#if defined(sun) || defined(__sun)
 static size_t strnlen(const char *str, size_t maxlen) {
     size_t i;
     for (i = 0; str[i] && i < maxlen; i++);
     return i;
 }
-#else
-#include <unistd.h> /* for strnlen() */
 #endif
-#endif
 
 #define VERSION "1.2.5"
 
