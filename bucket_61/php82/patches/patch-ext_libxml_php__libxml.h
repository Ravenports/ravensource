--- ext/libxml/php_libxml.h.orig	2023-11-21 09:55:59 UTC
+++ ext/libxml/php_libxml.h
@@ -35,6 +35,7 @@ extern zend_module_entry libxml_module_e
 
 #include "zend_smart_str.h"
 #include <libxml/tree.h>
+#include <libxml/parser.h>
 
 #define LIBXML_SAVE_NOEMPTYTAG 1<<2
 
