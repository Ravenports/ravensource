--- document.c.orig	2023-11-21 09:55:59 UTC
+++ document.c
@@ -26,6 +26,7 @@
 #ifdef LIBXML_SCHEMAS_ENABLED
 #include <libxml/relaxng.h>
 #include <libxml/xmlschemas.h>
+#include <libxml/xmlsave.h>
 #endif
 
 typedef struct _idsIterator idsIterator;
