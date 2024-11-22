--- src/gprlib.adb.orig	2024-10-07 12:45:16 UTC
+++ src/gprlib.adb
@@ -722,9 +722,6 @@ procedure Gprlib is
 
       for Dir of Imported_Library_Directories loop
          Library_Switches_Table.Append ("-L" & Dir);
-         if not Path_Option.Is_Empty then
-            Add_Rpath (Dir);
-         end if;
       end loop;
 
       for Libname of Imported_Library_Names loop
@@ -866,12 +863,6 @@ procedure Gprlib is
               Shared_Lib_Suffix.all);
       end if;
 
-      if not Path_Option.Is_Empty then
-         for Path of Library_Rpath_Options_Table loop
-            Add_Rpath (Path);
-         end loop;
-      end if;
-
       if not Path_Option.Is_Empty and then not Rpath.Is_Empty then
          if Separate_Run_Path_Options then
             for J in 1 .. Rpath.Last_Index loop
@@ -1411,7 +1402,7 @@ procedure Gprlib is
             end if;
 
          elsif Partial_Linker_Path = null then
-            Fail_Program (null, "unknown object file """ & Opt & """");
+            Put_Line ("WARNING: unknown object '" & Opt & "'");
          else
             Trailing_PL_Options.Append (Opt);
          end if;
@@ -2279,8 +2270,8 @@ procedure Gprlib is
 
                      Free (Libgnat);
                      Free (Libgnarl);
-                     Libgnat  := new String'("-lgnat-" & Line (6 .. Last));
-                     Libgnarl := new String'("-lgnarl-" & Line (6 .. Last));
+                     Libgnat  := new String'("-lgnat-" & Line (6 .. 7));
+                     Libgnarl := new String'("-lgnarl-" & Line (6 .. 7));
                   end if;
 
                else
