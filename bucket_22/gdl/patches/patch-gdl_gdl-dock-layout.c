--- gdl/gdl-dock-layout.c.orig	2018-10-22 19:36:04 UTC
+++ gdl/gdl-dock-layout.c
@@ -27,6 +27,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <libxml/parser.h>
+#include <libxml/xmlsave.h>
 #include <gtk/gtk.h>
 
 #include "gdl-dock-layout.h"
