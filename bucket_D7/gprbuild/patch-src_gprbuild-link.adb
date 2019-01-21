--- src/gprbuild-link.adb.orig	2018-05-25 06:23:18 UTC
+++ src/gprbuild-link.adb
@@ -1303,15 +1303,6 @@ package body Gprbuild.Link is
          Nam_Nod := Main_File.Tree.Shared.Name_Lists.Table
            (Main_Proj.Config.Run_Path_Option);
 
-         if Main_Proj.Config.Run_Path_Origin /= No_Name
-           and then Get_Name_String (Main_Proj.Config.Run_Path_Origin) /= ""
-         then
-            Rpaths_Relative_To
-              (Rpaths,
-               Main_Proj.Exec_Directory.Display_Name,
-               Main_Proj.Config.Run_Path_Origin);
-         end if;
-
          if Main_Proj.Config.Separate_Run_Path_Options then
             for Path of Rpaths loop
                Nam_Nod := Main_File.Tree.Shared.Name_Lists.Table
