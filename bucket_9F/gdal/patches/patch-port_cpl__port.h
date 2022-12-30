--- port/cpl_port.h.orig	2022-12-13 23:02:36 UTC
+++ port/cpl_port.h
@@ -607,7 +607,7 @@ static inline int CPLIsFinite(double f)
 }
 #else
 #  define CPLIsNan(x) isnan(x)
-#  if defined(isinf) || defined(__FreeBSD__)
+#  if defined(isinf) || defined(__FreeBSD__) || defined(__DragonFly__)
 /** Return whether a floating-pointer number is +/- infinity */
 #    define CPLIsInf(x) isinf(x)
 /** Return whether a floating-pointer number is finite */
