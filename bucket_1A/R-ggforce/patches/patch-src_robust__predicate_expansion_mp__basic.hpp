--- src/robust_predicate/expansion/mp_basic.hpp.orig	2024-09-17 12:38:32 UTC
+++ src/robust_predicate/expansion/mp_basic.hpp
@@ -86,7 +86,7 @@
         std::is_same<REAL_TYPE, double>::value;
 #   elif defined(FP_FAST_FMAF)
     bool constexpr _has_fma =
-        std::is_same<REAL_TYPE, single>::value;
+        std::is_same<REAL_TYPE, float>::value;
 #   else
     bool constexpr _has_fma = false;
 #   endif
