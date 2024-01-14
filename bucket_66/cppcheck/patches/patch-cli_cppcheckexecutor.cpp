--- cli/cppcheckexecutor.cpp.orig	2024-01-13 14:24:29 UTC
+++ cli/cppcheckexecutor.cpp
@@ -51,6 +51,7 @@
 #include <sstream> // IWYU pragma: keep
 #include <utility>
 #include <vector>
+#include <sys/wait.h>
 
 #ifdef USE_UNIX_SIGNAL_HANDLING
 #include "cppcheckexecutorsig.h"
