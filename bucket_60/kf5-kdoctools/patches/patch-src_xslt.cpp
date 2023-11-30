--- src/xslt.cpp.orig	2023-11-04 10:02:07 UTC
+++ src/xslt.cpp
@@ -14,6 +14,7 @@
 #include <libxml/parser.h>
 #include <libxml/parserInternals.h>
 #include <libxml/xmlIO.h>
+#include <libxml/xmlsave.h>
 #include <libxslt/transform.h>
 #include <libxslt/xsltInternals.h>
 #include <libxslt/xsltconfig.h>
