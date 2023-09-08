--- gnatstudio/src/gps-main.adb.orig	2023-05-10 09:41:12 UTC
+++ gnatstudio/src/gps-main.adb
@@ -781,30 +781,6 @@ procedure GPS.Main is
          end if;
       end;
 
-      --  Python startup path
-
-      declare
-         Python_Path : constant String := Env.Value ("PYTHONPATH", "");
-         New_Val     : String_Access;
-
-      begin
-         if Python_Path = "" then
-            New_Val := new String'
-              (+Create_From_Dir
-                 (Prefix_Dir, "share/gnatstudio/python").Full_Name);
-         else
-            New_Val := new String'
-              (+To_Path
-                 (From_Path (+Python_Path) &
-                  (1 => Create_From_Dir
-                       (Prefix_Dir, "share/gnatstudio/python"))));
-         end if;
-
-         Setenv ("PYTHONPATH", New_Val.all);
-         Trace (Me, "PYTHONPATH=" & New_Val.all);
-         Free (New_Val);
-      end;
-
       --  Temporary for DAP testing, to set gdb 13.x version
       --  Will be removed when gdb v. 13.x is default
       declare
