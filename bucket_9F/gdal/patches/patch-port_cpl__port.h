--- port/cpl_port.h.orig	2023-01-02 14:38:17 UTC
+++ port/cpl_port.h
@@ -673,7 +673,7 @@ extern "C++"
 }
 #else
 #define CPLIsNan(x) isnan(x)
-#if defined(isinf) || defined(__FreeBSD__)
+#if defined(isinf) || defined(__FreeBSD__) || defined(__DragonFly__)
 /** Return whether a floating-pointer number is +/- infinity */
 #define CPLIsInf(x) isinf(x)
 /** Return whether a floating-pointer number is finite */
