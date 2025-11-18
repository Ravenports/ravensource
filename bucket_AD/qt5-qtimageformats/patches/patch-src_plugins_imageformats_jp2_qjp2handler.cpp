--- src/plugins/imageformats/jp2/qjp2handler.cpp.orig	2024-05-08 05:14:43 UTC
+++ src/plugins/imageformats/jp2/qjp2handler.cpp
@@ -38,6 +38,7 @@
 **
 ****************************************************************************/
 
+#include <cmath>
 #include "qjp2handler_p.h"
 
 #include "qimage.h"
