--- src/gprbuild-post_compile.adb.orig	2018-05-25 06:23:18 UTC
+++ src/gprbuild-post_compile.adb
@@ -1718,7 +1718,10 @@ package body Gprbuild.Post_Compile is
          List : constant Name_List_Index :=
                   For_Project.Config.Run_Path_Option;
       begin
-         if Opt.Run_Path_Option and then List /= No_Name_List then
+         if Opt.Run_Path_Option and then
+            List /= No_Name_List and then
+            For_Project.Config.Run_Path_Origin /= No_Name
+         then
             Write_Name_List (Exchange_File, Run_Path_Option, List);
             Put_Line (Exchange_File,
                       Library_Label (Gprexch.Run_Path_Origin));
@@ -1890,11 +1893,7 @@ package body Gprbuild.Post_Compile is
                      end if;
 
                      if not OK then
-                        Error_Msg
-                          (Msg           => "unknown object file " &
-                                             Name_Buffer (1 .. Name_Len),
-                           Flag_Location => Library_Options.Location);
-                        Success := False;
+                        null;
                      end if;
 
                      List := Elem.Next;
