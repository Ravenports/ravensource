Avoid __extendhfsf2 and friends

--- src/corelib/global/qtypes.h.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/global/qtypes.h
@@ -274,23 +274,8 @@ using qsizetype = QIntegerForSizeof<std:
 
 // Define a native float16 type
 namespace QtPrivate {
-#if defined(__STDCPP_FLOAT16_T__)
-#  define QFLOAT16_IS_NATIVE        1
-using NativeFloat16Type = std::float16_t;
-#elif defined(Q_CC_CLANG) && defined(__FLT16_MAX__) && 0
-// disabled due to https://github.com/llvm/llvm-project/issues/56963
-#  define QFLOAT16_IS_NATIVE        1
-using NativeFloat16Type = decltype(__FLT16_MAX__);
-#elif defined(Q_CC_GNU_ONLY) && defined(__FLT16_MAX__) && defined(__ARM_FP16_FORMAT_IEEE)
-#  define QFLOAT16_IS_NATIVE        1
-using NativeFloat16Type = __fp16;
-#elif defined(Q_CC_GNU_ONLY) && defined(__FLT16_MAX__) && defined(__SSE2__)
-#  define QFLOAT16_IS_NATIVE        1
-using NativeFloat16Type = _Float16;
-#else
 #  define QFLOAT16_IS_NATIVE        0
 using NativeFloat16Type = void;
-#endif
 } // QtPrivate
 
 #endif // __cplusplus
