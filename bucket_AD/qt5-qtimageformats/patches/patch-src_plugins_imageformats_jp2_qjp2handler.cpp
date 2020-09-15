--- src/plugins/imageformats/jp2/qjp2handler.cpp.orig	2020-08-24 09:20:53 UTC
+++ src/plugins/imageformats/jp2/qjp2handler.cpp
@@ -38,6 +38,7 @@
 **
 ****************************************************************************/
 
+#include <cmath>
 #include "qjp2handler_p.h"
 
 #include "qimage.h"
