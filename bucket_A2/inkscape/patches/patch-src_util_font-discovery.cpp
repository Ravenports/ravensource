get_face method was removed (glib update?)

--- src/util/font-discovery.cpp.orig	2025-03-23 14:08:11 UTC
+++ src/util/font-discovery.cpp
@@ -312,12 +312,6 @@ std::shared_ptr<const std::vector<FontIn
     double counter = 0.0;
     for (auto ff : families) {
         bool synthetic_font = false;
-#if PANGO_VERSION_CHECK(1,46,0)
-        auto default_face = ff->get_face();
-        if (default_face && default_face->is_synthesized()) {
-            synthetic_font = true;
-        }
-#endif
         progress.report_or_throw(counter / families.size(), ff->get_name(), empty);
         std::vector<FontInfo> family;
         auto faces = ff->list_faces();
