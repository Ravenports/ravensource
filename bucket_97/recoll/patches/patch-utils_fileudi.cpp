--- utils/fileudi.cpp.orig	2025-02-13 06:56:20 UTC
+++ utils/fileudi.cpp
@@ -18,6 +18,7 @@
 
 #include <cstdlib>
 #include <iostream>
+#include <sys/types.h>
 
 #include "fileudi.h"
 #include "md5.h"
