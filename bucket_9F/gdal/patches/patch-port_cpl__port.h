--- port/cpl_port.h.orig	2025-05-06 16:38:15 UTC
+++ port/cpl_port.h
@@ -581,7 +581,7 @@ static inline char *CPL_afl_friendly_str
 #define CPLIsNan(x) __builtin_isnan(x)
 #define CPLIsInf(x) __builtin_isinf(x)
 #define CPLIsFinite(x) __builtin_isfinite(x)
-#elif defined(isinf) || defined(__FreeBSD__)
+#elif defined(isinf) || defined(__FreeBSD__) || defined(__DragonFly__)
 /** Return whether a floating-pointer number is nan */
 #define CPLIsNan(x) isnan(x)
 /** Return whether a floating-pointer number is +/- infinity */
