--- timidity/timidity.c.orig	2018-08-28 23:33:39 UTC
+++ timidity/timidity.c
@@ -25,16 +25,10 @@
 #include <sys/types.h>
 #endif //for off_t
 #include <stdio.h>
-#ifdef STDC_HEADERS
 #include <stdlib.h>
 #include <ctype.h>
 #include <stddef.h>
-#endif
-#ifndef NO_STRING_H
 #include <string.h>
-#else
-#include <strings.h>
-#endif
 #ifdef __W32__
 #include <windows.h>
 #include <io.h>
