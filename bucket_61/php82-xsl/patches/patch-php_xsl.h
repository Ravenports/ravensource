--- php_xsl.h.orig	2023-01-31 13:31:55 UTC
+++ php_xsl.h
@@ -37,7 +37,7 @@ extern zend_module_entry xsl_module_entr
 #include <libexslt/exsltconfig.h>
 #endif
 
-#include "../dom/xml_common.h"
+#include "ext/dom/xml_common.h"
 
 #include <libxslt/extensions.h>
 #include <libxml/xpathInternals.h>
