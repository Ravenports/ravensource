--- src/gprlib.adb.orig	2020-04-07 05:05:27 UTC
+++ src/gprlib.adb
@@ -751,9 +751,6 @@ procedure Gprlib is
 
       for Dir of Imported_Library_Directories loop
          Library_Switches_Table.Append ("-L" & Dir);
-         if Path_Option /= null then
-            Add_Rpath (Dir);
-         end if;
       end loop;
 
       for Libname of Imported_Library_Names loop
@@ -947,12 +944,6 @@ procedure Gprlib is
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
@@ -1484,9 +1475,7 @@ procedure Gprlib is
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
@@ -2135,10 +2124,10 @@ procedure Gprlib is
 
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
