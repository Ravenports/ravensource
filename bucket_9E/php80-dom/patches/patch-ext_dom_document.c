--- document.c.orig	2023-08-03 17:13:08 UTC
+++ document.c
@@ -26,6 +26,7 @@
 #ifdef LIBXML_SCHEMAS_ENABLED
 #include <libxml/relaxng.h>
 #include <libxml/xmlschemas.h>
+#include <libxml/xmlsave.h>
 #endif
 
 typedef struct _idsIterator idsIterator;