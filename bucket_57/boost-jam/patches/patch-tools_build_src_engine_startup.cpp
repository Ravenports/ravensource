--- tools/build/src/engine/startup.cpp.orig	2020-12-03 05:02:49 UTC
+++ tools/build/src/engine/startup.cpp
@@ -14,6 +14,7 @@ Distributed under the Boost Software Lic
 #include "output.h"
 #include "variable.h"
 
+#include <cstdlib>
 #include <string>
 #include <algorithm>
 
@@ -155,7 +156,12 @@ bool b2::startup::bootstrap(FRAME *frame
         }
     }
 
-    const std::string b2_exe_path{executable_path(saved_argv0)};
+    char *b2_exe_path_pchar = executable_path(saved_argv0);
+    const std::string b2_exe_path{b2_exe_path_pchar};
+    if (b2_exe_path_pchar)
+    {
+        std::free(b2_exe_path_pchar);
+    }
     const std::string boost_build_jam{"boost-build.jam"};
     std::string b2_file_path;
 
