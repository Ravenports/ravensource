--- numpy/core/include/numpy/npy_math.h.orig	2022-12-26 03:52:52 UTC
+++ numpy/core/include/numpy/npy_math.h
@@ -318,7 +318,11 @@ NPY_INPLACE npy_longdouble npy_tanl(npy_
 NPY_INPLACE npy_longdouble npy_expl(npy_longdouble x);
 NPY_INPLACE npy_longdouble npy_sqrtl(npy_longdouble x);
 NPY_INPLACE npy_longdouble npy_hypotl(npy_longdouble x, npy_longdouble y);
+#if defined(__NetBSD__)
+#define npy_log2l __builtin_log2l
+#else
 NPY_INPLACE npy_longdouble npy_log2l(npy_longdouble x);
+#endif
 NPY_INPLACE npy_longdouble npy_atan2l(npy_longdouble x, npy_longdouble y);
 NPY_INPLACE npy_longdouble npy_powl(npy_longdouble x, npy_longdouble y);
 NPY_INPLACE npy_longdouble npy_modfl(npy_longdouble x, npy_longdouble* y);
@@ -336,14 +340,22 @@ NPY_INPLACE npy_longdouble npy_modfl(npy
 #define npy_cbrtl cbrtl
 #define npy_log10l log10l
 #define npy_logl logl
+#if defined(__NetBSD__)
+#define npy_expm1l expm1
+#else
 #define npy_expm1l expm1l
+#endif
 #define npy_asinl asinl
 #define npy_acosl acosl
 #define npy_atanl atanl
 #define npy_asinhl asinhl
 #define npy_acoshl acoshl
 #define npy_atanhl atanhl
+#if defined(__NetBSD__)
+#define npy_log1pl log1p
+#else
 #define npy_log1pl log1pl
+#endif
 #define npy_exp2l exp2l
 #define npy_fmodl fmodl
 #define npy_frexpl frexpl
