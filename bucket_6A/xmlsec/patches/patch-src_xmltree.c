From 5f4e39b1a4f5823f64853d222722d7edcfaf4655 Mon Sep 17 00:00:00 2001
From: Aleksey Sanin <aleksey@aleksey.com>
Date: Wed, 24 Sep 2025 10:03:27 -0400
Subject: [PATCH] Fix build for LibXML2 > 2.15.0

---
 src/xmltree.c | 5 +++++
 1 file changed, 5 insertions(+)

--- src/xmltree.c.orig
+++ src/xmltree.c
@@ -24,6 +24,7 @@
 #include <libxml/valid.h>
 #include <libxml/xpath.h>
 #include <libxml/xpathInternals.h>
+#include <libxml/xmlversion.h>
 
 #include <xmlsec/xmlsec.h>
 #include <xmlsec/xmltree.h>
@@ -705,7 +706,11 @@ int
 xmlSecReplaceNodeBufferAndReturn(xmlNodePtr node, const xmlSecByte *buffer, xmlSecSize size, xmlNodePtr *replaced) {
     xmlNodePtr results = NULL;
     xmlNodePtr next = NULL;
+#if (LIBXML_VERSION >= 21500)
+    xmlChar *oldenc;
+#else  /* (LIBXML_VERSION >= 21500) */
     const xmlChar *oldenc;
+#endif /* (LIBXML_VERSION >= 21500) */
     int len;
     xmlParserErrors ret;
 
