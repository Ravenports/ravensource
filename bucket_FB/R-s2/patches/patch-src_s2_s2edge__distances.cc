--- src/s2/s2edge_distances.cc.orig	2025-01-07 11:51:24 UTC
+++ src/s2/s2edge_distances.cc
@@ -268,9 +268,9 @@ static double GetUpdateMinInteriorDistan
   // parallel to the plane containing the edge respectively.
   double b = min(1.0, 0.5 * dist.length2());
   double a = sqrt(b * (2 - b));
-  return ((2.5 + 2 * sqrt(3) + 8.5 * a) * a +
-          (2 + 2 * sqrt(3) / 3 + 6.5 * (1 - b)) * b +
-          (23 + 16 / sqrt(3)) * DBL_EPSILON) * DBL_EPSILON;
+  return ((2.5 + 2 * sqrt(3.0) + 8.5 * a) * a +
+          (2 + 2 * sqrt(3.0) / 3 + 6.5 * (1 - b)) * b +
+          (23 + 16 / sqrt(3.0)) * DBL_EPSILON) * DBL_EPSILON;
 }
 
 double GetUpdateMinDistanceMaxError(S1ChordAngle dist) {
