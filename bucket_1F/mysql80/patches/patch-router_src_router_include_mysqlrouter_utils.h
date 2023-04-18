--- router/src/router/include/mysqlrouter/utils.h.orig	2023-03-16 17:22:37 UTC
+++ router/src/router/include/mysqlrouter/utils.h
@@ -32,6 +32,7 @@
 #include <functional>
 #include <sstream>
 #include <string>
+#include <sys/stat.h>
 
 #include "my_compiler.h"  // MY_ATTRIBUTE
 
