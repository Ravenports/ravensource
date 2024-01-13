--- cli/cppcheckexecutor.cpp.intermediate	2023-12-23 06:29:47 UTC
+++ cli/cppcheckexecutor.cpp
@@ -51,6 +51,7 @@
 #include <sstream> // IWYU pragma: keep
 #include <utility>
 #include <vector>
+#include <sys/wait.h>
 
 #ifdef USE_UNIX_SIGNAL_HANDLING
 #include "cppcheckexecutorsig.h"
