--- gnatstudio/src/gps-main.adb.orig	2022-05-11 12:25:42 UTC
+++ gnatstudio/src/gps-main.adb
@@ -773,30 +773,6 @@ procedure GPS.Main is
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
       for J of Env.Keys loop
          Each_Environment_Variable (J, Env.Value (J));
       end loop;
