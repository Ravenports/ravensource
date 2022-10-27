--- src/Util.cpp.orig	2022-10-22 17:48:41 UTC
+++ src/Util.cpp
@@ -39,6 +39,7 @@ extern "C" {
 #include "third_party/base32hex.h"
 }
 
+#include <limits.h>
 #ifdef HAVE_DIRENT_H
 #  include <dirent.h>
 #endif
