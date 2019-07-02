--- src/gprlib.adb.orig	2019-05-18 04:47:57 UTC
+++ src/gprlib.adb
@@ -747,9 +747,6 @@ procedure Gprlib is
 
       for Dir of Imported_Library_Directories loop
          Library_Switches_Table.Append ("-L" & Dir);
-         if Path_Option /= null then
-            Add_Rpath (Dir);
-         end if;
       end loop;
 
       for Libname of Imported_Library_Names loop
@@ -944,12 +941,6 @@ procedure Gprlib is
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
@@ -1482,9 +1473,7 @@ procedure Gprlib is
                Object_Files.Append (Opt);
             else
                if Partial_Linker_Path = null then
-                  Fail_Program
-                    (null,
-                     "unknown object file """ & Opt & """");
+                  Put_Line ("WARNING: unknown object '" & Opt & "'");
                else
                   Trailing_PL_Options.Append (Opt);
                end if;
@@ -2143,10 +2132,10 @@ procedure Gprlib is
 
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
