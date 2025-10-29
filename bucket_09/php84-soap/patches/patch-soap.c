--- soap.c.orig	2025-09-23 14:14:32 UTC
+++ soap.c
@@ -20,11 +20,11 @@
 #include <config.h>
 #endif
 #include "php_soap.h"
-#include "ext/session/php_session.h"
+#include "../session/php_session.h"
 #include "soap_arginfo.h"
 #include "zend_exceptions.h"
 #include "zend_interfaces.h"
-#include "ext/standard/php_incomplete_class.h"
+#include "../standard/php_incomplete_class.h"
 
 /* We only have session support if PHP was configured with session support
  * or if the session module could be loaded dynamically, which will only
