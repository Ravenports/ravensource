--- router/src/router/include/mysqlrouter/utils.h.orig	2023-12-14 14:52:51 UTC
+++ router/src/router/include/mysqlrouter/utils.h
@@ -32,6 +32,7 @@
 #include <functional>
 #include <sstream>
 #include <string>
+#include <sys/stat.h>
 
 #include "my_compiler.h"  // MY_ATTRIBUTE
 
