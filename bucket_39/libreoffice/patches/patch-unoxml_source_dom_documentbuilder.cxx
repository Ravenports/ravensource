--- unoxml/source/dom/documentbuilder.cxx.orig	2023-09-22 19:07:01 UTC
+++ unoxml/source/dom/documentbuilder.cxx
@@ -21,6 +21,7 @@
 
 #include <string.h>
 
+#include <libxml/parser.h>
 #include <libxml/xmlerror.h>
 
 #include <memory>
