--- hacks/glx/platonicfolding.c.orig	2026-01-02 13:52:48 UTC
+++ hacks/glx/platonicfolding.c
@@ -935,7 +935,7 @@ static inline double get_current_julian_
    mathematical rigor: Mathematical setup, application and extension of a
    formula based on the subsolar point and atan2 function. Renewable Energy
    172:1333-1340, 2021. */
-static inline void get_sun_direction(double jd, float sun[4])
+static inline void get_sun_direction(double jd, float xxsun[4])
 {
   double n, utc;
   double l, g, gr, lambda, lambdar, epsilon, epsilonr;
@@ -958,10 +958,10 @@ static inline void get_sun_direction(dou
   lon = -15.0*(utc-12.0+eot*(4.0/60.0));
   latr = (float)rad(lat);
   lonr = (float)rad(lon);
-  sun[0] = cosf(latr)*cosf(lonr);
-  sun[1] = cosf(latr)*sinf(lonr);
-  sun[2] = sinf(latr);
-  sun[3] = 0.0f;
+  xxsun[0] = cosf(latr)*cosf(lonr);
+  xxsun[1] = cosf(latr)*sinf(lonr);
+  xxsun[2] = sinf(latr);
+  xxsun[3] = 0.0f;
 }
 
 #endif /* HAVE_GLSL */
