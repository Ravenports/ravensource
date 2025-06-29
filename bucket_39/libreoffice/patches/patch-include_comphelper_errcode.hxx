--- include/comphelper/errcode.hxx.orig	2025-06-05 10:22:59 UTC
+++ include/comphelper/errcode.hxx
@@ -24,6 +24,7 @@
 #include <ostream>
 #include <o3tl/typed_flags_set.hxx>
 #include <optional>
+#include <climits>
 #include <compare>
 
 #if defined(DBG_UTIL)
