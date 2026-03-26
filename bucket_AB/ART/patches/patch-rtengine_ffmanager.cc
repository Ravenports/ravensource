--- rtengine/ffmanager.cc.orig	2026-03-13 20:14:10 UTC
+++ rtengine/ffmanager.cc
@@ -104,10 +104,10 @@ double ffInfo::distance(const std::strin
     }
 
     double dAperture = 2 * (log(this->aperture) - log(aperture)) /
-                       log(2); // more important for vignette
+                       log(2.0); // more important for vignette
     double dfocallength =
-        (log(this->focallength / 100.) - log(focallength / 100.)) /
-        log(2); // more important for PRNU
+        (log(this->focallength / 100.0) - log(focallength / 100.0)) /
+        log(2.0); // more important for PRNU
 
     return sqrt(dfocallength * dfocallength + dAperture * dAperture);
 }
