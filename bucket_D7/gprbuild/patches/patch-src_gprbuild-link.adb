--- src/gprbuild-link.adb.orig	2024-10-07 12:45:16 UTC
+++ src/gprbuild-link.adb
@@ -3302,8 +3302,6 @@ package body Gprbuild.Link is
          if Opt.Run_Path_Option
            and then Main_Proj.Config.Run_Path_Option /= No_Name_List
          then
-            Add_Rpath_From_Arguments (Rpaths, Arguments, Main_Proj);
-            Add_Rpath_From_Arguments (Rpaths, Other_Arguments, Main_Proj);
             Add_Run_Path_Options;
          end if;
 
