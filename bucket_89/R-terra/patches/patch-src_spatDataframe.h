--- src/spatDataframe.h.orig	2023-03-02 02:47:27 UTC
+++ src/spatDataframe.h
@@ -25,6 +25,7 @@
 #include "spatBase.h"
 #include "spatTime.h"
 #include "spatFactor.h"
+#include <cstdint>
 #include <limits>
 
 class SpatDataFrame {
