--- src/ui/dialog/filedialogimpl-gtkmm.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/ui/dialog/filedialogimpl-gtkmm.cpp
@@ -1137,10 +1137,8 @@ void FileSaveDialogImplGtk::fileNameEntr
     if (!Glib::path_is_absolute(fileName)) {
         // try appending to the current path
         // not this way: fileName = get_current_folder() + "/" + fileName;
-        std::vector<Glib::ustring> pathSegments;
-        pathSegments.push_back(get_current_folder());
-        pathSegments.push_back(fileName);
-        fileName = Glib::build_filename(pathSegments);
+        std::string ss = get_current_folder() + "/" + fileName;
+        fileName = Glib::build_filename(ss);
     }
 
     // g_message("path:'%s'\n", fileName.c_str());
