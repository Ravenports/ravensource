--- drawinglayer/source/tools/primitive2dxmldump.cxx.orig	2025-03-21 15:34:31 UTC
+++ drawinglayer/source/tools/primitive2dxmldump.cxx
@@ -12,6 +12,7 @@
 #include <rtl/string.hxx>
 #include <tools/stream.hxx>
 #include <tools/XmlWriter.hxx>
+#include <libxml/parser.h>
 
 #include <math.h>
 #include <memory>
