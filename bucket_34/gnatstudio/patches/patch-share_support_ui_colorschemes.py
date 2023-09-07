--- share/support/ui/colorschemes.py.orig	2022-05-11 12:25:42 UTC
+++ share/support/ui/colorschemes.py
@@ -37,7 +37,7 @@ darkside = Theme("Darkside", False, {
 })
 
 color_theme_pref = GPS.Preference("/Color-Theme").create(
-    "Color theme", "string", "Darkside")
+    "Color theme", "string", "Tomorrow")
 
 monokai = Theme("Monokai", False, {
     "debugger_current": Rgba(58, 71, 54, 153),
