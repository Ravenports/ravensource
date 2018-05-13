--- frmts/mrf/mrf_band.cpp.orig	2018-05-04 16:07:31 UTC
+++ frmts/mrf/mrf_band.cpp
@@ -49,7 +49,7 @@
 
 #include <vector>
 #include <assert.h>
-#include "../zlib/zlib.h"
+#include <zlib.h>
 
 CPL_CVSID("$Id: mrf_band.cpp 7e07230bbff24eb333608de4dbd460b7312839d0 2017-12-11 19:08:47Z Even Rouault $")
 
