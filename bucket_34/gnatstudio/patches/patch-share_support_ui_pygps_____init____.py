--- share/support/ui/pygps/__init__.py.orig	2023-05-10 09:41:12 UTC
+++ share/support/ui/pygps/__init__.py
@@ -396,7 +396,7 @@ try:
     # it is better to directly call the appropriate GPS action or menu
     # rather than rely on these functions
 
-    if "linux" in sys.platform:
+    if True:
         GDK_BACKSPACE = 65288
         GDK_TAB = 65289
         GDK_RETURN = Gdk.KEY_Return
