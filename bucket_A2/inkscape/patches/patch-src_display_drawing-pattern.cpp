--- src/display/drawing-pattern.cpp.orig	2023-07-16 14:32:51 UTC
+++ src/display/drawing-pattern.cpp
@@ -87,7 +87,7 @@ cairo_pattern_t *DrawingPattern::renderP
             if (rect.dimensions()[i] >= _pattern_resolution[i]) {
                 rect[i] = {0, _pattern_resolution[i]};
             } else {
-                rect[i] -= Util::rounddown(rect[i].min(), _pattern_resolution[i]);
+                rect[i] -= Util::inkscape_rounddown(rect[i].min(), _pattern_resolution[i]);
             }
         }
         return rect;
@@ -99,7 +99,7 @@ cairo_pattern_t *DrawingPattern::renderP
             int const period = _pattern_resolution[i];
             if (a[i].extent() >= period) return true;
             if (b[i].extent() > a[i].extent()) return false;
-            return Util::rounddown(b[i].min() - a[i].min(), period) >= b[i].max() - a[i].max();
+            return Util::inkscape_rounddown(b[i].min() - a[i].min(), period) >= b[i].max() - a[i].max();
         };
         return check(0) && check(1);
     };
@@ -110,7 +110,7 @@ cairo_pattern_t *DrawingPattern::renderP
             int const period = _pattern_resolution[i];
             if (a[i].extent() >= period) return true;
             if (b[i].extent() >= period) return true;
-            return Util::rounddown(b[i].max() - a[i].min(), period) >= b[i].min() - a[i].max();
+            return Util::inkscape_rounddown(b[i].max() - a[i].min(), period) >= b[i].min() - a[i].max();
         };
         return check(0) && check(1);
     };
@@ -119,8 +119,8 @@ cairo_pattern_t *DrawingPattern::renderP
     auto overlapping_translates = [&, this] (Geom::IntRect const &a, Geom::IntRect const &b) {
         Geom::IntPoint min, max;
         for (int i = 0; i < 2; i++) {
-            min[i] = Util::roundup  (b[i].min() - a[i].max() + 1, _pattern_resolution[i]);
-            max[i] = Util::rounddown(b[i].max() - a[i].min() - 1, _pattern_resolution[i]);
+            min[i] = Util::inkscape_roundup  (b[i].min() - a[i].max() + 1, _pattern_resolution[i]);
+            max[i] = Util::inkscape_rounddown(b[i].max() - a[i].min() - 1, _pattern_resolution[i]);
         }
         return std::make_pair(min, max);
     };
@@ -163,7 +163,7 @@ cairo_pattern_t *DrawingPattern::renderP
 
             for (auto it = surfaces.begin(); it != surfaces.end(); ) {
                 if (wrapped_touches(expanded, it->rect)) {
-                    expanded.unionWith(it->rect + rounddown(expanded.max() - it->rect.min(), _pattern_resolution));
+                    expanded.unionWith(it->rect + inkscape_rounddown(expanded.max() - it->rect.min(), _pattern_resolution));
                     merged.emplace_back(std::move(*it));
                     *it = std::move(surfaces.back());
                     surfaces.pop_back();
@@ -254,7 +254,7 @@ cairo_pattern_t *DrawingPattern::renderP
 
     // Create and return pattern.
     auto cp = cairo_pattern_create_for_surface(surface->surface->cobj());
-    auto const shift = surface->rect.min() + rounddown(area_orig.min() - surface->rect.min(), _pattern_resolution);
+    auto const shift = surface->rect.min() + inkscape_rounddown(area_orig.min() - surface->rect.min(), _pattern_resolution);
     ink_cairo_pattern_set_matrix(cp, pattern_to_tile * Geom::Translate(-shift));
     cairo_pattern_set_extend(cp, CAIRO_EXTEND_REPEAT);
     return cp;
