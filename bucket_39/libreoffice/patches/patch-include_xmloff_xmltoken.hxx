--- include/xmloff/xmltoken.hxx.orig	2025-01-12 19:04:12 UTC
+++ include/xmloff/xmltoken.hxx
@@ -24,6 +24,7 @@
 #include <xmloff/dllapi.h>
 #include <rtl/ustring.hxx>
 #include <sax/fastattribs.hxx>
+#undef XML_EMPTY	/* Collision with xmlversion.h */
 
 /**
  * Handling of tokens in XML:
