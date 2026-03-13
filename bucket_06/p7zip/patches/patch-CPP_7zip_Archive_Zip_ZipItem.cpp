--- CPP/7zip/Archive/Zip/ZipItem.cpp.orig	2024-10-17 08:03:40 UTC
+++ CPP/7zip/Archive/Zip/ZipItem.cpp
@@ -3,6 +3,7 @@
 #if (!defined _WIN32) && (!defined __CYGWIN__) && (!defined __APPLE__)
 #include <iconv.h>
 #include <locale.h>
+#include <strings.h>
 #endif
 
 #include "StdAfx.h"
