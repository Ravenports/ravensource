--- re.h.orig	2016-10-22 12:40:44 UTC
+++ re.h
@@ -4,6 +4,9 @@
 					allows the fully ISO-Charset.
 */
 
+#include <string.h>
+#include <stdlib.h>
+
 /*************************************************************
  *							     *
  * 	Macros defining special characters.		     *
