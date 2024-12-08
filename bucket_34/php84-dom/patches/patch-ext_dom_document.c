--- document.c.orig	2024-11-20 09:48:35 UTC
+++ document.c
@@ -31,6 +31,7 @@
 #ifdef LIBXML_SCHEMAS_ENABLED
 #include <libxml/relaxng.h>
 #include <libxml/xmlschemas.h>
+#include <libxml/xmlsave.h>
 #endif
 
 /*
