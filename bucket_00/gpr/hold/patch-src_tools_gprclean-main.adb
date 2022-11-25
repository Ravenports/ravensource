--- src/tools/gprclean-main.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprclean-main.adb
@@ -659,7 +659,7 @@ procedure GPRclean.Main is
 
 begin
    GNATCOLL.Traces.Parse_Config_File;
-   GPRtools.Util.Set_Program_Name ("gprclean");
+   GPRtools.Util.Set_Program_Name ("gpr2clean");
    GPRclean.Options.Setup (Parser);
 
    Options.Tree := Project_Tree.Reference;
