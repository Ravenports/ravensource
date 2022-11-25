--- src/tools/gprinstall-main.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprinstall-main.adb
@@ -55,7 +55,7 @@ procedure GPRinstall.Main is
    use Ada.Strings.Unbounded;
 
 begin
-   GPRtools.Util.Set_Program_Name ("gprinstall");
+   GPRtools.Util.Set_Program_Name ("gpr2install");
 
    --  Initialize and read the command line arguments
 
