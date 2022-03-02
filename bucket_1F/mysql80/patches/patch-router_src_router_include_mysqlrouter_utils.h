--- router/src/router/include/mysqlrouter/utils.h.orig	2021-12-17 16:07:27 UTC
+++ router/src/router/include/mysqlrouter/utils.h
@@ -30,6 +30,7 @@
 #include <functional>
 #include <sstream>
 #include <string>
+#include <sys/stat.h>
 
 #include "my_compiler.h"  // MY_ATTRIBUTE
 
