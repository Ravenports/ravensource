--- gtk/a11y/gtkaccessibility.c.orig	2025-01-25 13:25:12 UTC
+++ gtk/a11y/gtkaccessibility.c
@@ -37,7 +37,7 @@
 #include <gtk/gtktogglebutton.h>
 #include <gtk/gtkaccessible.h>
 
-#ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
 #include <atk-bridge.h>
 #endif
 
@@ -986,7 +986,7 @@ _gtk_accessibility_init (void)
   _gtk_accessibility_override_atk_util ();
   do_window_event_initialization ();
 
-#ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_init (NULL, NULL);
 #endif
 
