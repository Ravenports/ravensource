--- src_editor/src/completion_module.adb.orig	2017-05-12 17:58:17 UTC
+++ src_editor/src/completion_module.adb
@@ -1587,7 +1587,8 @@ package body Completion_Module is
       then
          Completion_Module.Trigger_Timeout :=
            Glib.Main.Timeout_Add
-             (Interval => Guint (Smart_Completion_Trigger_Timeout.Get_Pref),
+             (Interval =>
+                Guint (Integer'(Smart_Completion_Trigger_Timeout.Get_Pref)),
               Func     => Trigger_Timeout_Callback'Access);
 
          Completion_Module.Has_Trigger_Timeout := True;
