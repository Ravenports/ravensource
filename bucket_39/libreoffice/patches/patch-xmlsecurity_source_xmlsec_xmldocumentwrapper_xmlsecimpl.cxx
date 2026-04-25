--- xmlsecurity/source/xmlsec/xmldocumentwrapper_xmlsecimpl.cxx.orig	2026-04-09 16:07:27 UTC
+++ xmlsecurity/source/xmlsec/xmldocumentwrapper_xmlsecimpl.cxx
@@ -27,6 +27,7 @@
 #include "xmlelementwrapper_xmlsecimpl.hxx"
 #include <comphelper/attributelist.hxx>
 #include <rtl/ref.hxx>
+#include <libxml/valid.h>
 
 #ifdef UNX
 #define stricmp strcasecmp
