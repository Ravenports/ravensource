--- Str.c.orig	2025-08-20 09:32:27 UTC
+++ Str.c
@@ -18,9 +18,7 @@
 #include <gc/gc.h>
 #include <stdarg.h>
 #include <string.h>
-#ifdef __EMX__			/* or include "fm.h" for HAVE_BCOPY? */
 #include <strings.h>
-#endif
 #include "Str.h"
 #include "myctype.h"
 
