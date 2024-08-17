see https://github.com/r-lib/ragg/issues/170

--- src/agg/src/agg_font_freetype.cpp.orig	2024-04-05 06:58:14 UTC
+++ src/agg/src/agg_font_freetype.cpp
@@ -179,7 +179,7 @@ namespace agg
             v_control = v_start;
 
             point = outline.points + first;
-            tags  = outline.tags  + first;
+            tags  = (char*)outline.tags  + first;
             tag   = FT_CURVE_TAG(tags[0]);
 
             // A contour cannot start with a cubic control point!
