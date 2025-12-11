--- drawinglayer/source/tools/primitive2dxmldump.cxx.orig	2025-12-01 19:30:03 UTC
+++ drawinglayer/source/tools/primitive2dxmldump.cxx
@@ -12,6 +12,7 @@
 #include <rtl/string.hxx>
 #include <tools/stream.hxx>
 #include <tools/XmlWriter.hxx>
+#include <libxml/parser.h>
 
 #include <math.h>
 #include <memory>
