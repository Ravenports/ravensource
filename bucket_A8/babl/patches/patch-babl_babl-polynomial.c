--- babl/babl-polynomial.c.orig	2026-03-10 15:56:45 UTC
+++ babl/babl-polynomial.c
@@ -531,7 +531,7 @@ babl_polynomial_approximate_gamma (BablP
   babl_assert (scale >= BABL_POLYNOMIAL_MIN_SCALE &&
                scale <= BABL_POLYNOMIAL_MAX_SCALE);
 
-  basis = alloca ((degree + 1) * sizeof (BablPolynomial));
+  basis = __builtin_alloca ((degree + 1) * sizeof (BablPolynomial));
 
   babl_polynomial_orthonormal_basis (basis, degree + 1, x0, x1, scale);
 
