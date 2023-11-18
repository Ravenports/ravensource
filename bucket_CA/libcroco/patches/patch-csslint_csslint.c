--- csslint/csslint.c.orig	2019-04-06 16:37:03 UTC
+++ csslint/csslint.c
@@ -25,6 +25,7 @@
 
 #include "libcroco.h"
 #include <libxml/xpath.h>
+#include <libxml/parser.h>
 
 #include <glib.h>
 #include <string.h>
