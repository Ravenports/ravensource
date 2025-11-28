--- src/plugins/imageformats/jp2/qjp2handler.cpp.orig	2024-11-20 13:56:40 UTC
+++ src/plugins/imageformats/jp2/qjp2handler.cpp
@@ -38,6 +38,7 @@
 **
 ****************************************************************************/
 
+#include <cmath>
 #include "qjp2handler_p.h"
 
 #include "qimage.h"
