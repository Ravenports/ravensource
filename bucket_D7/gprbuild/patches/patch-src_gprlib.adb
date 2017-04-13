--- src/gprlib.adb.orig	2016-12-23 15:59:49.000000000 +0000
+++ src/gprlib.adb	2017-04-13 22:45:53.000000000 +0000
@@ -413,6 +413,11 @@
 
    Separate_Run_Path_Options : Boolean := False;
 
+      Rpath_Disabled : Boolean := False;
+      --  If -R is passed through the library options for the linker, it will
+      --  prevent the implemented libraries portion of the rpath switch from
+      --  being built, even if the linker is capable of supporting rpath.
+
    Rpath : String_List_Access := null;
    --  Allocated only if Path Option is supported
 
@@ -908,7 +913,7 @@
          Library_Switches_Table.Append
            (new String'("-L" & Imported_Library_Directories.Table (J).all));
 
-         if Path_Option /= null then
+         if not Rpath_Disabled and then Path_Option /= null then
             Add_Rpath (Imported_Library_Directories.Table (J));
          end if;
 
@@ -2160,7 +2165,12 @@
                   Use_GNAT_Lib := False;
                end if;
 
-               Library_Options_Table.Append (new String'(Line (1 .. Last)));
+               if Line (1 .. Last) = "-R" then
+                  Rpath_Disabled := True;
+               else
+                  Library_Options_Table.Append
+                    (new String'(Line (1 .. Last)));
+               end if;
 
             when Gprexch.Library_Rpath_Options =>
                Library_Rpath_Options_Table.Append
@@ -2295,10 +2305,10 @@
 
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
