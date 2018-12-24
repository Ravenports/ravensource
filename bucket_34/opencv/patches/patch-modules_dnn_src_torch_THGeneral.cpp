--- modules/dnn/src/torch/THGeneral.cpp.orig	2018-12-21 14:31:20 UTC
+++ modules/dnn/src/torch/THGeneral.cpp
@@ -2,7 +2,11 @@
 
 #if defined(TH_DISABLE_HEAP_TRACKING)
 #elif (defined(__unix) || defined(_WIN32))
+#  if defined __FreeBSD__ || defined __DragonFly__
+#include <stdlib.h>
+#  else
 #include <malloc.h>
+#  endif
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
 #endif
