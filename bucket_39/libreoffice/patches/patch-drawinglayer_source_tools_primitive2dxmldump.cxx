--- drawinglayer/source/tools/primitive2dxmldump.cxx.orig	2026-04-09 16:07:27 UTC
+++ drawinglayer/source/tools/primitive2dxmldump.cxx
@@ -13,6 +13,7 @@
 #include <rtl/ustrbuf.hxx>
 #include <tools/stream.hxx>
 #include <tools/XmlWriter.hxx>
+#include <libxml/parser.h>
 
 #include <memory>
 #include <libxml/parser.h>
