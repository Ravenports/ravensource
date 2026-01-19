--- src/gui/gtk.c.orig	2025-12-20 17:20:27 UTC
+++ src/gui/gtk.c
@@ -51,6 +51,9 @@
 #ifdef GDK_WINDOWING_WAYLAND
 #include <gdk/gdkwayland.h>
 #endif
+#ifdef GDK_WINDOWING_X11
+#include <gdk/gdkx.h>
+#endif
 #include <gtk/gtk.h>
 #include <math.h>
 #include <stdlib.h>
@@ -995,7 +998,7 @@ dt_gui_session_type_t dt_gui_get_session
     : DT_GUI_SESSION_X11;
 #elif defined(GDK_WINDOWING_X11)
   GdkDisplay* disp = gdk_display_get_default();
-  retun G_TYPE_CHECK_INSTANCE_TYPE(disp, GDK_TYPE_X11_DISPLAY)
+  return G_TYPE_CHECK_INSTANCE_TYPE(disp, GDK_TYPE_X11_DISPLAY)
     ? DT_GUI_SESSION_X11
     : DT_GUI_SESSION_WAYLAND;
 #else
