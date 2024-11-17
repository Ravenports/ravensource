--- timidity/au_a.c.orig	2008-04-01 02:35:08 UTC
+++ timidity/au_a.c
@@ -26,6 +26,9 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <ctype.h>
 
 #ifdef __POCC__
 #include <sys/types.h>
