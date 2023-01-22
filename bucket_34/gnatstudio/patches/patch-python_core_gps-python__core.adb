--- python/core/gps-python_core.adb.orig	2022-05-11 12:25:42 UTC
+++ python/core/gps-python_core.adb
@@ -43,8 +43,7 @@ package body GPS.Python_Core is
          if Python_Home.Is_Empty then
             declare
                Packaged_Python_Location : constant Virtual_File :=
-                 Create (+Executable_Location)
-                 / (+"share") / (+"gnatstudio") / (+"python");
+                 Create (+Executable_Location);
             begin
                Register_Python_Scripting
                  (Kernel.Scripts,
