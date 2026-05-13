--- libemf/libemf.h.orig	2026-05-04 19:14:29 UTC
+++ libemf/libemf.h
@@ -27,6 +27,17 @@
 #include <algorithm>
 #include <stdexcept>
 #include <memory>
+#include <type_traits>
+
+/* Type-agnostic fallbacks for legacy code across Ravenports platforms */
+template <typename T, typename U>
+inline typename std::common_type<T, U>::type (max)(T a, U b) { return (a > b) ? a : b; }
+
+template <typename T, typename U>
+inline typename std::common_type<T, U>::type (min)(T a, U b) { return (a < b) ? a : b; }
+
+using std::max;
+using std::min;
 
 #include <config.h>
 #include <libEMF/emf.h>
