--- drawinglayer/source/tools/primitive2dxmldump.cxx.orig	2025-01-23 21:25:49 UTC
+++ drawinglayer/source/tools/primitive2dxmldump.cxx
@@ -12,6 +12,7 @@
 #include <rtl/string.hxx>
 #include <tools/stream.hxx>
 #include <tools/XmlWriter.hxx>
+#include <libxml/parser.h>
 
 #include <math.h>
 #include <memory>
