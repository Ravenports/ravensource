--- libguile/numbers.c.orig	2020-03-07 17:29:32 UTC
+++ libguile/numbers.c
@@ -45,7 +45,9 @@
 #  include <config.h>
 #endif
 
+#if (__GNUC__ * 10 + __GNUC_MINOR__ >= 46)
 #include <verify.h>
+#endif
 #include <assert.h>
 
 #include <math.h>
@@ -191,7 +193,7 @@ static double atanh (double x) { return
 
 
 #if defined (GUILE_I)
-#if defined HAVE_COMPLEX_DOUBLE
+#if defined HAVE_COMPLEX_DOUBLE && (HAVE_CLOG || HAVE_CLOG10 || HAVE_CEXP || HAVE_USABLE_CSQRT) && defined (SCM_COMPLEX_VALUE)
 
 /* For an SCM object Z which is a complex number (ie. satisfies
    SCM_COMPLEXP), return its value as a C level "complex double". */
