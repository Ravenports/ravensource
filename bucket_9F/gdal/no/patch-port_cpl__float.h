--- port/cpl_float.h.orig	2025-05-06 16:38:15 UTC
+++ port/cpl_float.h
@@ -658,11 +658,7 @@ template <> struct NumericLimits<Float16
 
 }  // namespace cpl
 
-#ifdef HAVE_STD_FLOAT16_T
-using GFloat16 = std::float16_t;
-#else
 using GFloat16 = cpl::Float16;
-#endif
 
 // Define some GDAL wrappers. Their C equivalents are defined in `cpl_port.h`.
 // (These wrappers are not necessary any more in C++, one can always
