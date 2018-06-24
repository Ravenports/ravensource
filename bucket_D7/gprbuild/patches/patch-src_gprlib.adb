--- src/gprlib.adb.orig	2018-05-25 06:23:18 UTC
+++ src/gprlib.adb
@@ -271,6 +271,11 @@ procedure Gprlib is
 
    Separate_Run_Path_Options     : Boolean := False;
 
+   --  If -R is passed through the library options for the linker, it will
+   --  prevent the implemented libraries portion of the rpath switch from
+   --  being built, even if the linker is capable of supporting rpath.
+   Rpath_Disabled                : Boolean := False;
+
    Rpath_Origin                  : String_Access := null;
 
    Rpath                         : String_Vectors.Vector;
@@ -720,7 +725,7 @@ procedure Gprlib is
 
       for Dir of Imported_Library_Directories loop
          Library_Switches_Table.Append ("-L" & Dir);
-         if Path_Option /= null then
+         if not Rpath_Disabled and then Path_Option /= null then
             Add_Rpath (Dir);
          end if;
       end loop;
@@ -1468,9 +1473,7 @@ procedure Gprlib is
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
@@ -1872,7 +1875,11 @@ procedure Gprlib is
                   Use_GNAT_Lib := False;
                end if;
 
-               Library_Options_Table.Append (Line (1 .. Last));
+               if Line (1 .. Last) = "-R" then
+                  Rpath_Disabled := True;
+               else
+                  Library_Options_Table.Append (Line (1 .. Last));
+               end if;
 
             when Gprexch.Library_Rpath_Options =>
                Library_Rpath_Options_Table.Append (Line (1 .. Last));
@@ -2002,10 +2009,10 @@ procedure Gprlib is
 
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
