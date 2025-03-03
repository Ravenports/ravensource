--- utils/fileudi.cpp.orig	2024-12-20 08:12:32 UTC
+++ utils/fileudi.cpp
@@ -18,6 +18,7 @@
 
 #include <cstdlib>
 #include <iostream>
+#include <sys/types.h>
 
 #include "fileudi.h"
 #include "md5.h"
