--- src/Util.cpp.orig	2023-03-12 21:00:43 UTC
+++ src/Util.cpp
@@ -41,6 +41,7 @@ extern "C" {
 #include "third_party/base32hex.h"
 }
 
+#include <limits.h>
 #ifdef HAVE_DIRENT_H
 #  include <dirent.h>
 #endif
