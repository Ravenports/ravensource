--- src_editor/src/src_editor_buffer.adb.orig	2017-05-12 17:58:17 UTC
+++ src_editor/src/src_editor_buffer.adb
@@ -3585,7 +3585,7 @@ package body Src_Editor_Buffer is
          B.Timeout_Registered := False;
       end if;
 
-      Timeout := Gint (Periodic_Save.Get_Pref);
+      Timeout := Gint (Integer'(Periodic_Save.Get_Pref));
 
       if Timeout > 0 then
          B.Timeout_Id := Buffer_Timeout.Timeout_Add
