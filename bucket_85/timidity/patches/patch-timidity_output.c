--- timidity/output.c.orig	2013-11-03 10:55:02 UTC
+++ timidity/output.c
@@ -25,12 +25,8 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
-#ifdef STDC_HEADERS
 #include <string.h>
 #include <ctype.h>
-#elif HAVE_STRINGS_H
-#include <strings.h>
-#endif
 #include "timidity.h"
 #include "common.h"
 #include "output.h"
