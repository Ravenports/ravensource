--- prog/aspell.cpp.orig	2011-07-04 09:13:58 UTC
+++ prog/aspell.cpp
@@ -25,6 +25,7 @@
 # include <langinfo.h>
 #endif
 
+#include "errors.hpp"
 #include "aspell.h"
 
 #ifdef USE_FILE_INO
@@ -40,7 +41,6 @@
 #include "convert.hpp"
 #include "document_checker.hpp"
 #include "enumeration.hpp"
-#include "errors.hpp"
 #include "file_util.hpp"
 #include "fstream.hpp"
 #include "info.hpp"
