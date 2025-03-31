--- include/comphelper/errcode.hxx.orig	2025-03-21 15:34:31 UTC
+++ include/comphelper/errcode.hxx
@@ -24,6 +24,7 @@
 #include <ostream>
 #include <o3tl/typed_flags_set.hxx>
 #include <optional>
+#include <climits>
 #include <compare>
 
 #if defined(DBG_UTIL)
