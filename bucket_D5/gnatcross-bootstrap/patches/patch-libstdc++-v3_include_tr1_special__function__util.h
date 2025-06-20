--- libstdc++-v3/include/tr1/special_function_util.h.orig	2024-08-01 08:17:18 UTC
+++ libstdc++-v3/include/tr1/special_function_util.h
@@ -105,7 +105,7 @@ namespace tr1
       };
 
 
-#if _GLIBCXX_USE_C99_MATH && !_GLIBCXX_USE_C99_FP_MACROS_DYNAMIC
+#if _GLIBCXX_USE_C99_MATH && !_GLIBCXX_USE_C99_FP_MACROS_DYNAMIC && !defined(__sun)
 
     /// This is a wrapper for the isnan function. Otherwise, for NaN,
     /// all comparisons result in false. If/when we build a std::isnan
