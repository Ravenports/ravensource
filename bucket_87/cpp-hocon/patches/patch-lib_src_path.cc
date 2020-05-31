--- lib/src/path.cc.orig	2019-12-12 09:56:44 UTC
+++ lib/src/path.cc
@@ -1,3 +1,4 @@
+#include <algorithm>
 #include <hocon/path.hpp>
 #include <hocon/config_exception.hpp>
 #include <internal/path_builder.hpp>
