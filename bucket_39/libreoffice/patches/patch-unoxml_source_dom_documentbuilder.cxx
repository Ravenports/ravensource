--- unoxml/source/dom/documentbuilder.cxx.orig	2024-04-29 18:46:10 UTC
+++ unoxml/source/dom/documentbuilder.cxx
@@ -21,6 +21,7 @@
 
 #include <string.h>
 
+#include <libxml/parser.h>
 #include <libxml/xmlerror.h>
 #include <libxml/parser.h>
 
