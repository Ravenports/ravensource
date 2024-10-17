--- utils/fileudi.cpp.orig	2024-09-02 15:46:49 UTC
+++ utils/fileudi.cpp
@@ -18,6 +18,7 @@
 
 #include <cstdlib>
 #include <iostream>
+#include <sys/types.h>
 
 #include "fileudi.h"
 #include "md5.h"
