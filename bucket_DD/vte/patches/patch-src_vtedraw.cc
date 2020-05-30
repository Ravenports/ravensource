--- src/vtedraw.cc.orig	2020-05-13 09:51:07 UTC
+++ src/vtedraw.cc
@@ -2319,13 +2319,13 @@ _vte_draw_draw_line(struct _vte_draw *dr
 static inline double
 _vte_draw_get_undercurl_rad(gint width)
 {
-        return width / 2. / sqrt(2);
+        return width / 2. / sqrt((double)2);
 }
 
 static inline double
 _vte_draw_get_undercurl_arc_height(gint width)
 {
-        return _vte_draw_get_undercurl_rad(width) * (1. - sqrt(2) / 2.);
+        return _vte_draw_get_undercurl_rad(width) * (1. - sqrt((double)2) / 2.);
 }
 
 double
