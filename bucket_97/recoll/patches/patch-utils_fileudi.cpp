--- utils/fileudi.cpp.orig	2021-12-18 18:09:05 UTC
+++ utils/fileudi.cpp
@@ -18,6 +18,7 @@
 
 #include <cstdlib>
 #include <iostream>
+#include <sys/types.h>
 
 #include "fileudi.h"
 #include "md5.h"
