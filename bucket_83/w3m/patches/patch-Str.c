--- Str.c.orig	2023-01-21 02:01:52 UTC
+++ Str.c
@@ -18,9 +18,7 @@
 #include <gc.h>
 #include <stdarg.h>
 #include <string.h>
-#ifdef __EMX__			/* or include "fm.h" for HAVE_BCOPY? */
 #include <strings.h>
-#endif
 #include "Str.h"
 #include "myctype.h"
 
