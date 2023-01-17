--- pythran/xsimd/arch/xsimd_scalar.hpp.orig	2023-01-17 19:26:30 UTC
+++ pythran/xsimd/arch/xsimd_scalar.hpp
@@ -442,6 +442,7 @@ namespace xsimd
     }
 
 #if defined(_GNU_SOURCE) && !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__ANDROID__)
+# if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
     inline float exp10(const float& x) noexcept
     {
         return ::exp10f(x);
@@ -450,6 +451,7 @@ namespace xsimd
     {
         return ::exp10(x);
     }
+# endif
 #endif
 
     template <class T, class = typename std::enable_if<std::is_scalar<T>::value>::type>
