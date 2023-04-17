--- qt/Application.h.orig	2023-04-14 02:22:25 UTC
+++ qt/Application.h
@@ -16,6 +16,7 @@
 
 #include <libtransmission/tr-macros.h>
 
+#include <time.h>
 #include "FaviconCache.h"
 #include "Typedefs.h"
 #include "Utils.h" // std::hash<QString>
