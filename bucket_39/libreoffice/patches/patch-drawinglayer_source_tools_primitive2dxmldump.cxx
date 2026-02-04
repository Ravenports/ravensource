--- drawinglayer/source/tools/primitive2dxmldump.cxx.orig	2026-01-27 21:11:38 UTC
+++ drawinglayer/source/tools/primitive2dxmldump.cxx
@@ -13,6 +13,7 @@
 #include <rtl/ustrbuf.hxx>
 #include <tools/stream.hxx>
 #include <tools/XmlWriter.hxx>
+#include <libxml/parser.h>
 
 #include <memory>
 #include <libxml/parser.h>
