--- include/xmloff/xmltoken.hxx.orig	2025-03-21 15:34:31 UTC
+++ include/xmloff/xmltoken.hxx
@@ -24,6 +24,7 @@
 #include <xmloff/dllapi.h>
 #include <rtl/ustring.hxx>
 #include <sax/fastattribs.hxx>
+#undef XML_EMPTY	/* Collision with xmlversion.h */
 
 /**
  * Handling of tokens in XML:
