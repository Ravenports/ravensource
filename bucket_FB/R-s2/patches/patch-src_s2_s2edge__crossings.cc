--- src/s2/s2edge_crossings.cc.orig	2025-01-07 11:51:24 UTC
+++ src/s2/s2edge_crossings.cc
@@ -271,7 +271,7 @@ inline static bool IsNormalizable(const
   //
   // The fastest way to ensure this is to test whether the largest component of
   // the result has a magnitude of at least 2**-242.
-  return max(fabs(p[0]), max(fabs(p[1]), fabs(p[2]))) >= ldexp(1, -242);
+  return max(fabs(p[0]), max(fabs(p[1]), fabs(p[2]))) >= ldexp(1.0, -242);
 }
 
 // Scales a 3-vector as necessary to ensure that the result can be normalized
@@ -292,7 +292,7 @@ inline static Vector3_d EnsureNormalizab
     double p_max = max(fabs(p[0]), max(fabs(p[1]), fabs(p[2])));
 
     // The expression below avoids signed overflow for any value of ilogb().
-    return ldexp(2, -1 - ilogb(p_max)) * p;
+    return ldexp(2.0, -1 - ilogb(p_max)) * p;
   }
   return p;
 }
