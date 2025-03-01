--- src/stream/slice.cpp.orig	2025-03-01 20:25:52.622238000 +0100
+++ src/stream/slice.cpp	2025-03-01 20:26:16.811804000 +0100
@@ -27,6 +27,7 @@
 #include <boost/cstdint.hpp>
 #include <boost/algorithm/string/predicate.hpp>
 #include <boost/filesystem/operations.hpp>
+#include <boost/filesystem/directory.hpp>
 #include <boost/range/size.hpp>
 
 #include "util/console.hpp"
