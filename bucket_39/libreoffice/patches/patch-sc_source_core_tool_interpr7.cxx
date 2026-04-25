--- sc/source/core/tool/interpr7.cxx.orig	2026-04-09 16:07:27 UTC
+++ sc/source/core/tool/interpr7.cxx
@@ -19,6 +19,7 @@
 #include <tools/urlobj.hxx>
 
 #include <officecfg/Office/Common.hxx>
+#include <libxml/parser.h>
 #include <libxml/xpath.h>
 #include <datastreamgettime.hxx>
 #include <dpobject.hxx>
