--- src/main.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/main.cpp
@@ -1068,10 +1068,8 @@ sp_main_gui(int argc, char const **argv)
     for (std::vector<Glib::ustring>::iterator it = dataDirs.begin(); it != dataDirs.end(); ++it)
     {
         std::vector<Glib::ustring> listing;
-        listing.push_back(*it);
-        listing.push_back("inkscape");
-        listing.push_back("icons");
-        Glib::ustring dir = Glib::build_filename(listing);
+        std::string ss = *it + "/inkscape/icons";
+        Glib::ustring dir = Glib::build_filename(ss);
         gtk_icon_theme_append_search_path(gtk_icon_theme_get_default(), dir.c_str());
     }
 
