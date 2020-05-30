--- lib/src/path.cc.orig	2018-10-11 16:55:40 UTC
+++ lib/src/path.cc
@@ -1,3 +1,4 @@
+#include <algorithm>
 #include <hocon/path.hpp>
 #include <hocon/config_exception.hpp>
 #include <internal/path_builder.hpp>
