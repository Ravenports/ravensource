--- plug-ins/drs/dia-render-script-import.c.orig	2014-08-24 15:46:01 UTC
+++ plug-ins/drs/dia-render-script-import.c
@@ -27,6 +27,7 @@
 #include "color.h"
 #include "diagramdata.h"
 
+#include <libxml/parser.h>
 #include <libxml/tree.h>
 
 static real
