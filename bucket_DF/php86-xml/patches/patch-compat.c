--- compat.c.orig	2025-09-23 14:14:32 UTC
+++ compat.c
@@ -14,6 +14,10 @@
    +----------------------------------------------------------------------+
  */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #if defined(HAVE_LIBXML) && (defined(HAVE_XML) || defined(HAVE_XMLRPC)) && !defined(HAVE_LIBEXPAT)
 #include "expat_compat.h"
