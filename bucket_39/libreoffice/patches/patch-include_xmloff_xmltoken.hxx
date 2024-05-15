--- include/xmloff/xmltoken.hxx.orig	2024-04-29 18:46:10 UTC
+++ include/xmloff/xmltoken.hxx
@@ -24,6 +24,7 @@
 #include <xmloff/dllapi.h>
 #include <rtl/ustring.hxx>
 #include <sax/fastattribs.hxx>
+#undef XML_EMPTY	/* Collision with xmlversion.h */
 
 /**
  * Handling of tokens in XML:
