--- ext/generate.c.orig	2026-02-20 16:03:30 UTC
+++ ext/generate.c
@@ -4,6 +4,7 @@
  * The redistribution terms are provided in the COPYRIGHT file that must
  * be distributed with this source code.
  */
+#define __EXTENSIONS__
 #include <stdio.h>
 #include <string.h>
 #include <stdarg.h>
