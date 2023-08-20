--- DAEValidator/library/src/XmlDoc.cpp.orig	2018-11-26 22:43:10 UTC
+++ DAEValidator/library/src/XmlDoc.cpp
@@ -1,5 +1,6 @@
 #include "Macros.h"
 
+#include <cstdint>
 #if IS_GNUC_AND_GNUC_VERSION_LT(5,1,1)
 #include <cstring>
 #endif
