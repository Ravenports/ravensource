--- src/tools/gprremote.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprremote.adb
@@ -402,7 +402,7 @@ procedure GPRremote is
    end Prolog;
 
 begin
-   GPRtools.Util.Set_Program_Name ("gprremote");
+   GPRtools.Util.Set_Program_Name ("gpr2remote");
 
    Parse_Command_Line;
 
