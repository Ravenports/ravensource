--- src/helper/mathfns.h.orig	2022-10-04 18:03:23 UTC
+++ src/helper/mathfns.h
@@ -79,16 +79,16 @@ T constexpr safemod(T a, T b)
 
 /// Returns \a a rounded down to the nearest multiple of \a b, assuming b >= 1.
 template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
-T constexpr rounddown(T a, T b)
+T constexpr inkscape_rounddown(T a, T b)
 {
     return a - safemod(a, b);
 }
 
 /// Returns \a a rounded up to the nearest multiple of \a b, assuming b >= 1.
 template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
-T constexpr roundup(T a, T b)
+T constexpr inkscape_roundup(T a, T b)
 {
-    return rounddown(a - 1, b) + b;
+    return inkscape_rounddown(a - 1, b) + b;
 }
 
 /**
