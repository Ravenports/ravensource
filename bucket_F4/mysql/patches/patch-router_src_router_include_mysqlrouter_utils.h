--- router/src/router/include/mysqlrouter/utils.h.orig	2024-06-07 11:57:16 UTC
+++ router/src/router/include/mysqlrouter/utils.h
@@ -35,6 +35,7 @@
 #include <functional>
 #include <sstream>
 #include <string>
+#include <sys/stat.h>
 
 #include "my_compiler.h"  // MY_ATTRIBUTE
 
