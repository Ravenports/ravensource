--- router/src/router/include/mysqlrouter/utils.h.orig	2026-07-10 11:18:36 UTC
+++ router/src/router/include/mysqlrouter/utils.h
@@ -35,6 +35,7 @@
 #include <functional>
 #include <sstream>
 #include <string>
+#include <sys/stat.h>
 
 #include "my_compiler.h"  // MY_ATTRIBUTE
 
