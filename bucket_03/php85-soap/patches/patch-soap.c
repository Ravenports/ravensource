--- soap.c.orig	2025-11-18 08:02:20 UTC
+++ soap.c
@@ -20,12 +20,12 @@
 #include <config.h>
 #endif
 #include "php_soap.h"
-#include "ext/session/php_session.h"
+#include "../session/php_session.h"
 #include "zend_attributes.h"
 #include "soap_arginfo.h"
 #include "zend_exceptions.h"
 #include "zend_interfaces.h"
-#include "ext/standard/php_incomplete_class.h"
+#include "../standard/php_incomplete_class.h"
 
 /* We only have session support if PHP was configured with session support
  * or if the session module could be loaded dynamically, which will only
