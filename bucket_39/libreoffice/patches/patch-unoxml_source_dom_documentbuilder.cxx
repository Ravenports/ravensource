--- unoxml/source/dom/documentbuilder.cxx.orig	2024-07-10 15:12:43 UTC
+++ unoxml/source/dom/documentbuilder.cxx
@@ -21,6 +21,7 @@
 
 #include <string.h>
 
+#include <libxml/parser.h>
 #include <libxml/xmlerror.h>
 #include <libxml/parser.h>
 
