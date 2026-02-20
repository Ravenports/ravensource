--- ext/pgm_options.c.orig	2026-02-20 16:03:30 UTC
+++ ext/pgm_options.c
@@ -5,6 +5,7 @@
  * be distributed with this source code.
  */
 
+#define __EXTENSIONS__
 #include <stdio.h>
 #include <stdlib.h>
 #include <limits.h>
