--- sc/source/core/tool/interpr7.cxx.orig	2026-01-14 23:16:14 UTC
+++ sc/source/core/tool/interpr7.cxx
@@ -19,6 +19,7 @@
 #include <tools/urlobj.hxx>
 
 #include <officecfg/Office/Common.hxx>
+#include <libxml/parser.h>
 #include <libxml/xpath.h>
 #include <datastreamgettime.hxx>
 #include <dpobject.hxx>
