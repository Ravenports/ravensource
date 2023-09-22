--- src/gprbuild-link.adb.orig	2023-07-13 10:29:21 UTC
+++ src/gprbuild-link.adb
@@ -3135,8 +3135,6 @@ package body Gprbuild.Link is
          if Opt.Run_Path_Option
            and then Main_Proj.Config.Run_Path_Option /= No_Name_List
          then
-            Add_Rpath_From_Arguments (Rpaths, Arguments, Main_Proj);
-            Add_Rpath_From_Arguments (Rpaths, Other_Arguments, Main_Proj);
             Add_Run_Path_Options;
          end if;
 
