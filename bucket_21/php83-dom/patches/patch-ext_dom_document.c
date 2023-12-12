--- document.c.orig	2023-11-21 14:40:35 UTC
+++ document.c
@@ -27,6 +27,7 @@
 #ifdef LIBXML_SCHEMAS_ENABLED
 #include <libxml/relaxng.h>
 #include <libxml/xmlschemas.h>
+#include <libxml/xmlsave.h>
 #endif
 
 typedef struct _idsIterator idsIterator;
