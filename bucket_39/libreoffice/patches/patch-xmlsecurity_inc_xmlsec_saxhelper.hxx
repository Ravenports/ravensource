--- xmlsecurity/inc/xmlsec/saxhelper.hxx.orig	2023-09-22 19:07:01 UTC
+++ xmlsecurity/inc/xmlsec/saxhelper.hxx
@@ -23,6 +23,7 @@
 
 #include <string_view>
 
+#include <libxml/parser.h>
 #include <libxml/tree.h>
 
 #include <rtl/ustring.hxx>
