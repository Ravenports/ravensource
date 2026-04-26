--- src/s2/s2edge_crosser.cc.orig	2025-01-07 11:51:24 UTC
+++ src/s2/s2edge_crosser.cc
@@ -63,7 +63,7 @@ inline int S2EdgeCrosserBase<PointRep>::
   // DotProd() below is DBL_EPSILON.  (There is also a small relative error
   // term that is insignificant because we are comparing the result against a
   // constant that is very close to zero.)
-  static const double kError = (1.5 + 1/sqrt(3)) * DBL_EPSILON;
+  static const double kError = (1.5 + 1/sqrt(3.0)) * DBL_EPSILON;
   if ((c_->DotProd(a_tangent_) > kError && d.DotProd(a_tangent_) > kError) ||
       (c_->DotProd(b_tangent_) > kError && d.DotProd(b_tangent_) > kError)) {
     return -1;
