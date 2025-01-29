--- unoxml/source/dom/documentbuilder.cxx.orig	2025-01-23 21:25:49 UTC
+++ unoxml/source/dom/documentbuilder.cxx
@@ -21,6 +21,7 @@
 
 #include <string.h>
 
+#include <libxml/parser.h>
 #include <libxml/xmlerror.h>
 #include <libxml/parser.h>
 
