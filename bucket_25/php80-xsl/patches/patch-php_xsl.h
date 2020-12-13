--- php_xsl.h.orig	2020-11-24 17:04:03 UTC
+++ php_xsl.h
@@ -37,7 +37,7 @@ extern zend_module_entry xsl_module_entr
 #include <libexslt/exsltconfig.h>
 #endif
 
-#include "../dom/xml_common.h"
+#include "ext/dom/xml_common.h"
 
 #include <libxslt/extensions.h>
 #include <libxml/xpathInternals.h>
