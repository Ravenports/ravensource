--- storage/connect/plgxml.h.orig	2025-02-11 19:05:58 UTC
+++ storage/connect/plgxml.h
@@ -5,7 +5,8 @@
 /******************************************************************/
 /*  Dual XML implementation base classes defines.                 */
 /******************************************************************/
-#if !defined(BASE_BUFFER_SIZE)
+#include <libxml/tree.h>
+#if 0
 enum ElementType {               // libxml2
      XML_ELEMENT_NODE       =  1,
      XML_ATTRIBUTE_NODE     =  2,
