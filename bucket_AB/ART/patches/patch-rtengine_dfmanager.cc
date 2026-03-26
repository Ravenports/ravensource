--- rtengine/dfmanager.cc.orig	2026-03-13 20:14:10 UTC
+++ rtengine/dfmanager.cc
@@ -101,8 +101,8 @@ double DFInfo::distance(const std::strin
         return INFINITY;
     }
 
-    double dISO = (log(this->iso / 100.) - log(iso / 100.)) / log(2);
-    double dShutter = (log(this->shutter) - log(shutter)) / log(2);
+    double dISO = (log(this->iso / 100.0) - log(iso / 100.0)) / log(2.0);
+    double dShutter = (log(this->shutter) - log(shutter)) / log(2.0);
     return sqrt(dISO * dISO + dShutter * dShutter);
 }
 
