--- third_party/externals/dng_sdk/source/dng_safe_arithmetic.h.orig	2019-03-13 04:56:20 UTC
+++ third_party/externals/dng_sdk/source/dng_safe_arithmetic.h
@@ -109,20 +109,6 @@ std::int64_t SafeInt64MultSlow(std::int6
 
 // Internal function used as optimization for SafeInt64Mult() if Clang
 // __builtin_smull_overflow is supported. Don't call this function directly.
-#if __has_builtin(__builtin_smull_overflow)
-inline std::int64_t SafeInt64MultByClang(std::int64_t arg1, std::int64_t arg2) {
-  std::int64_t result;
-#if (__WORDSIZE == 64) && !defined(__APPLE__)
-  if (__builtin_smull_overflow(arg1, arg2, &result)) {
-#else
-  if (__builtin_smulll_overflow(arg1, arg2, &result)) {
-#endif
-    ThrowProgramError("Arithmetic overflow");
-    abort();  // Never reached.
-  }
-  return result;
-}
-#endif
 
 // Internal function used as optimization for SafeInt64Mult() if __int128 type
 // is supported. Don't call this function directly.
@@ -147,9 +133,7 @@ inline std::int64_t SafeInt64MultByInt12
 // (without overflow). Otherwise, throws a dng_exception with error code
 // dng_error_unknown.
 inline std::int64_t SafeInt64Mult(std::int64_t arg1, std::int64_t arg2) {
-#if __has_builtin(__builtin_smull_overflow)
-  return dng_internal::SafeInt64MultByClang(arg1, arg2);
-#elif defined(DNG_HAS_INT128)
+#if defined(DNG_HAS_INT128)
   return dng_internal::SafeInt64MultByInt128(arg1, arg2);
 #else
   return dng_internal::SafeInt64MultSlow(arg1, arg2);
