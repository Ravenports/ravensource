--- timidity/raw_a.c.orig	2008-04-01 02:35:08 UTC
+++ timidity/raw_a.c
@@ -27,6 +27,9 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <ctype.h>
 
 #ifdef __POCC__
 #include <sys/types.h>
