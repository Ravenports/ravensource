--- src_editor/src/src_editor_view.adb.orig	2017-05-12 17:58:17 UTC
+++ src_editor/src/src_editor_view.adb
@@ -1095,7 +1095,7 @@ package body Src_Editor_View is
       ----------------
 
       procedure Draw_Above is
-         Column    : constant Gint := Gint (Highlight_Column.Get_Pref);
+         Column : constant Gint := Gint (Integer'(Highlight_Column.Get_Pref));
 
          procedure Draw_Block (B : in out Block_Record);
          --  Draw block B
