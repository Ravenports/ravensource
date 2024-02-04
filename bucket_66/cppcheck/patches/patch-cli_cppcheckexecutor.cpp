--- cli/cppcheckexecutor.cpp.orig	2024-01-23 12:30:57 UTC
+++ cli/cppcheckexecutor.cpp
@@ -51,6 +51,7 @@
 #include <sstream> // IWYU pragma: keep
 #include <utility>
 #include <vector>
+#include <sys/wait.h>
 
 #ifdef USE_UNIX_SIGNAL_HANDLING
 #include "cppcheckexecutorsig.h"
