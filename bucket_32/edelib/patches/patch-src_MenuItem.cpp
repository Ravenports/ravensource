--- src/MenuItem.cpp.orig	2014-06-21 23:24:07.000000000 +0200
+++ src/MenuItem.cpp	2025-10-14 21:13:53.516402000 +0200
@@ -44,6 +44,12 @@
 # include <Carbon/Carbon.h>
 #endif
 
+#if (FL_MAJOR_VERSION >= 1) && (FL_MINOR_VERSION > 3)
+# define CLEAR_OVERLAY set_flag(NO_OVERLAY)
+#else
+# define CLEAR_OVERLAY clear_overlay()
+#endif
+
 /* do not allow arrows to stretch; looks bad */
 #define FLTK_FIXED_ARROW_SIZE 1
 
@@ -305,7 +311,7 @@
   set_modal();
   clear_border();
   menu = L;
-  if (L->labelcolor_ || Fl::scheme() || L->labeltype_ > FL_NO_LABEL) clear_overlay();
+  if (L->labelcolor_ || Fl::scheme() || L->labeltype_ > FL_NO_LABEL) CLEAR_OVERLAY;
 }
 
 menuwindow::menuwindow(const MenuItem* m, int X, int Y, int Wp, int Hp,
@@ -394,7 +400,7 @@
       w1 = int(fl_width(fl_shortcut_label(m->shortcut_))) + 8;
       if (w1 > hotKeysw) hotKeysw = w1;
     }
-    if (m->labelcolor_ || Fl::scheme() || m->labeltype_ > FL_NO_LABEL) clear_overlay();
+    if (m->labelcolor_ || Fl::scheme() || m->labeltype_ > FL_NO_LABEL) CLEAR_OVERLAY;
   }
 
   if (selected >= 0 && !Wp) X -= W/2;
@@ -403,7 +409,8 @@
   if (Wp > W) W = Wp;
   if (Wtitle > W) W = Wtitle;
 
-  if (X < scr_x) X = scr_x; if (X > scr_x+scr_w-W) X= scr_x+scr_w-W;
+  if (X < scr_x) X = scr_x;
+  if (X > scr_x+scr_w-W) X = scr_x+scr_w-W;
   x(X); w(W);
 
   h((numitems ? itemheight*numitems-LEADING : 0)+2*BW+3);
