--- share/support/ui/pygps/__init__.py.orig	2025-09-19 10:04:04 UTC
+++ share/support/ui/pygps/__init__.py
@@ -431,7 +431,7 @@ try:
     # it is better to directly call the appropriate GPS action or menu
     # rather than rely on these functions
 
-    if "linux" in sys.platform:
+    if True:
         GDK_BACKSPACE = 65288
         GDK_TAB = 65289
         GDK_RETURN = Gdk.KEY_Return
