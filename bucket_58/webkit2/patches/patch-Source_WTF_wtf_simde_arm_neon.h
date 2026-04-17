--- Source/WTF/wtf/simde/arm/neon.h.orig	2025-08-11 07:56:53 UTC
+++ Source/WTF/wtf/simde/arm/neon.h
@@ -6811,41 +6811,10 @@ HEDLEY_DIAGNOSTIC_POP
  * will not be defined, so if you can handle that situation sensibly
  * you may need to sprinkle some ifdefs into your code.
  */
-#if \
-    (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || \
-    (0 && HEDLEY_HAS_FEATURE(c_alignof))
-  #define SIMDE_ALIGN_OF(Type) _Alignof(Type)
-#elif \
-    (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
-    (0 && HEDLEY_HAS_FEATURE(cxx_alignof))
-  #define SIMDE_ALIGN_OF(Type) alignof(Type)
-#elif \
-    HEDLEY_GCC_VERSION_CHECK(2,95,0) || \
-    HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
-    HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
-    HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) || \
-    HEDLEY_TINYC_VERSION_CHECK(0,9,24) || \
-    HEDLEY_PGI_VERSION_CHECK(19,10,0) || \
-    HEDLEY_CRAY_VERSION_CHECK(10,0,0) || \
-    HEDLEY_TI_ARMCL_VERSION_CHECK(16,9,0) || \
-    HEDLEY_TI_CL2000_VERSION_CHECK(16,9,0) || \
-    HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0) || \
-    HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
-    HEDLEY_TI_CL430_VERSION_CHECK(16,9,0) || \
-    HEDLEY_TI_CLPRU_VERSION_CHECK(2,3,2) || \
-    HEDLEY_MCST_LCC_VERSION_CHECK(1,25,10) || \
-    defined(__IBM__ALIGNOF__) || \
-    defined(__clang__)
+#if defined(__GNUC__) || defined(__clang__)
   #define SIMDE_ALIGN_OF(Type) __alignof__(Type)
-#elif \
-  HEDLEY_IAR_VERSION_CHECK(8,40,0)
-  #define SIMDE_ALIGN_OF(Type) __ALIGNOF__(Type)
-#elif \
-  HEDLEY_MSVC_VERSION_CHECK(19,0,0)
-  /* Probably goes back much further, but MS takes down their old docs.
-   * If you can verify that this works in earlier versions please let
-   * me know! */
-  #define SIMDE_ALIGN_OF(Type) __alignof(Type)
+#elif defined(__cplusplus) && (__cplusplus >= 201103L)
+  #define SIMDE_ALIGN_OF(Type) alignof(Type)
 #endif
 
 /* SIMDE_ALIGN_MAXIMUM:
@@ -7744,7 +7713,7 @@ typedef SIMDE_POLY128_TYPE simde_poly128
 #endif
 
 /* TODO: detect compilers which support this outside of C11 mode */
-#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
+#if !defined(__cplusplus) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
   #define SIMDE_CHECKED_REINTERPRET_CAST(to, from, value) _Generic((value), to: (value), default: (_Generic((value), from: ((to) (value)))))
   #define SIMDE_CHECKED_STATIC_CAST(to, from, value) _Generic((value), to: (value), default: (_Generic((value), from: ((to) (value)))))
 #else
