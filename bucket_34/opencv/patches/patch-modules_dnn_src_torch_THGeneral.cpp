--- modules/dnn/src/torch/THGeneral.cpp.orig	2017-08-03 23:58:23 UTC
+++ modules/dnn/src/torch/THGeneral.cpp
@@ -3,7 +3,11 @@
 
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
