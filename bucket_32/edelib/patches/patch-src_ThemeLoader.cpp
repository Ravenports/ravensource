--- src/ThemeLoader.cpp.orig	2014-06-21 23:24:07.000000000 +0200
+++ src/ThemeLoader.cpp	2025-10-14 21:13:53.529239000 +0200
@@ -116,7 +116,7 @@
 static void update_fonts(int sz) {
 #ifdef EDELIB_HAVE_RTTI
 	for(Fl_Window *i = Fl::first_window(); i; i = Fl::next_window(i))
-		update_fonts_on_group(i, sz);
+		update_fonts_on_group((Fl_Group*)i, sz);
 #else
 	Fl::redraw();
 #endif
