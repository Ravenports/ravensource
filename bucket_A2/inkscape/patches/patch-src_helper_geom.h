--- src/helper/geom.h.orig	2023-07-16 14:33:04 UTC
+++ src/helper/geom.h
@@ -55,10 +55,10 @@ inline Geom::Coord triangle_area(Geom::P
     return p1[X] * p2[Y] + p1[Y] * p3[X] + p2[X] * p3[Y] - p2[Y] * p3[X] - p1[Y] * p2[X] - p1[X] * p3[Y];
 }
 
-inline auto rounddown(Geom::IntPoint const &a, Geom::IntPoint const &b)
+inline auto inkscape_rounddown(Geom::IntPoint const &a, Geom::IntPoint const &b)
 {
     using namespace Inkscape::Util;
-    return Geom::IntPoint(rounddown(a.x(), b.x()), rounddown(a.y(), b.y()));
+    return Geom::IntPoint(inkscape_rounddown(a.x(), b.x()), inkscape_rounddown(a.y(), b.y()));
 }
 
 inline auto expandedBy(Geom::IntRect rect, int amount)
