--- share/support/ui/theme_handling.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/ui/theme_handling.py
@@ -145,7 +145,7 @@ class Color:
             if len(from_rgba) == 4:
                 self.a = from_rgba[3] / 255.0
         else:
-            rgba_values = re.findall("\d+", from_pref)
+            rgba_values = re.findall(r"\d+", from_pref)
             self.r, self.g, self.b = (int(x) / 255.0 for x in rgba_values[0:3])
             if len(rgba_values) == 4:
                 self.a = int(rgba_values[3]) / 255.0
