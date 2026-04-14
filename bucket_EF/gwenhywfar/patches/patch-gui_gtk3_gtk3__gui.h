--- gui/gtk3/gtk3_gui.h.orig	2023-07-27 22:01:05 UTC
+++ gui/gtk3/gtk3_gui.h
@@ -14,7 +14,7 @@
 #include <gtk/gtk.h>
 
 
-#if (defined __GNUC__ && (! defined (__sun)) && (__GNUC__ >= 4 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))) || defined _MSC_VER
+#if (defined __GNUC__                        && (__GNUC__ >= 4 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))) || defined _MSC_VER
 # ifdef BUILDING_GTK3_GUI
 #   define GTK3GUI_API __attribute__ ((visibility("default")))
 # else
