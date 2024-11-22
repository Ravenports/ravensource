--- share/support/ui/pygps/__init__.py.orig	2024-11-01 10:55:18 UTC
+++ share/support/ui/pygps/__init__.py
@@ -430,7 +430,7 @@ try:
     # it is better to directly call the appropriate GPS action or menu
     # rather than rely on these functions
 
-    if "linux" in sys.platform:
+    if True:
         GDK_BACKSPACE = 65288
         GDK_TAB = 65289
         GDK_RETURN = Gdk.KEY_Return
