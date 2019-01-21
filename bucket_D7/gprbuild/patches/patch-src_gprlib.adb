--- src/gprlib.adb.orig	2018-05-25 06:23:18 UTC
+++ src/gprlib.adb
@@ -720,9 +720,6 @@ procedure Gprlib is
 
       for Dir of Imported_Library_Directories loop
          Library_Switches_Table.Append ("-L" & Dir);
-         if Path_Option /= null then
-            Add_Rpath (Dir);
-         end if;
       end loop;
 
       for Libname of Imported_Library_Names loop
@@ -917,12 +914,6 @@ procedure Gprlib is
               Shared_Lib_Suffix.all);
       end if;
 
-      if Path_Option /= null then
-         for Path of Library_Rpath_Options_Table loop
-            Add_Rpath (Path);
-         end loop;
-      end if;
-
       if Path_Option /= null and then not Rpath.Is_Empty then
          if Separate_Run_Path_Options then
             for J in 1 .. Rpath.Last_Index loop
@@ -1468,9 +1459,7 @@ procedure Gprlib is
                if Is_Regular_File (Object_Path) then
                   Object_Files.Append (Object_Path);
                else
-                  Fail_Program
-                    (null,
-                     "unknown object file """ & Object_Path & """");
+                  Put_Line ("WARNING: unknown object '" & Object_Path & "'");
                end if;
             end;
          end loop;
@@ -2002,10 +1991,10 @@ procedure Gprlib is
 
                      Libgnat :=
                        new String'
-                         ("-lgnat-" & Line (6 .. Last));
+                         ("-lgnat-" & Line (6));
                      Libgnarl :=
                        new String'
-                         ("-lgnarl-" & Line (6 .. Last));
+                         ("-lgnarl-" & Line (6));
                   end if;
 
                else
