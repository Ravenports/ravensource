--- src/tools/gprdump.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprdump.adb
@@ -268,7 +268,7 @@ procedure GPRdump is
 
 begin
    GNATCOLL.Traces.Parse_Config_File;
-   GPRtools.Util.Set_Program_Name ("gprdump");
+   GPRtools.Util.Set_Program_Name ("gpr2dump");
    Parse_Command_Line;
 
    if Options.Display_Sources
