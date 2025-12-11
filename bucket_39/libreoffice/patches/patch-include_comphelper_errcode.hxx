--- include/comphelper/errcode.hxx.orig	2025-12-01 19:30:03 UTC
+++ include/comphelper/errcode.hxx
@@ -25,6 +25,7 @@
 #include <ostream>
 #include <o3tl/typed_flags_set.hxx>
 #include <optional>
+#include <climits>
 #include <compare>
 
 #if defined(DBG_UTIL)
