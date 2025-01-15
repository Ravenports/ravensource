--- xmlsecurity/source/xmlsec/xmldocumentwrapper_xmlsecimpl.cxx.orig	2025-01-12 19:04:12 UTC
+++ xmlsecurity/source/xmlsec/xmldocumentwrapper_xmlsecimpl.cxx
@@ -27,6 +27,7 @@
 #include "xmlelementwrapper_xmlsecimpl.hxx"
 #include <comphelper/attributelist.hxx>
 #include <rtl/ref.hxx>
+#include <libxml/valid.h>
 
 #ifdef UNX
 #define stricmp strcasecmp
