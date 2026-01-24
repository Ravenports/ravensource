--- unoxml/source/dom/documentbuilder.cxx.orig	2026-01-14 23:16:14 UTC
+++ unoxml/source/dom/documentbuilder.cxx
@@ -21,6 +21,7 @@
 
 #include <string.h>
 
+#include <libxml/parser.h>
 #include <libxml/xmlerror.h>
 #include <libxml/parser.h>
 
