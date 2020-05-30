--- src/lib_json/json_reader.cpp.orig	2020-05-29 13:50:26 UTC
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
