--- src/lib_json/json_reader.cpp.orig	2019-11-12 07:16:54 UTC
+++ src/lib_json/json_reader.cpp
@@ -4,6 +4,11 @@
 // recognized in your jurisdiction.
 // See file LICENSE for detail or copy at http://jsoncpp.sourceforge.net/LICENSE
 
+// fix for lang/gcc5+
+#if __GNUC__ == 5
+#include <cstdio>
+#endif
+
 #if !defined(JSON_IS_AMALGAMATION)
 #include "json_tool.h"
 #include <json/assertions.h>
