--- src/engine/math_tools.cpp.orig	2026-04-12 03:02:21 UTC
+++ src/engine/math_tools.cpp
@@ -28,7 +28,7 @@ double fheroes2::GetAngle( const Point &
 {
     const int dx = target.x - start.x;
     const int dy = target.y - start.y;
-    double angle = atan2( -dy, dx ) * 180.0 / M_PI;
+    double angle = atan2( static_cast<double>(-dy), static_cast<double>(dx) ) * 180.0 / M_PI;
     // we only care about two quadrants, normalize
     if ( dx < 0 ) {
         angle = ( dy <= 0 ) ? 180 - angle : -angle - 180;
