--- src/tools/gprdoc-main.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprdoc-main.adb
@@ -96,7 +96,7 @@ procedure GPRdoc.Main is
          Allow_Quiet        => False);
       Group  : constant GPRtools.Command_Line.Argument_Group :=
         Parser.Add_Argument_Group
-          ("gprdoc", On_Switch'Unrestricted_Access);
+          ("gpr2doc", On_Switch'Unrestricted_Access);
 
    begin
       Setup (Tool => GPRtools.Inspect);
@@ -120,7 +120,7 @@ begin
 
    --  Set program name
 
-   GPRtools.Util.Set_Program_Name ("gprdoc");
+   GPRtools.Util.Set_Program_Name ("gpr2doc");
 
    --  Run the GPRdoc main procedure depending on command line options
 
@@ -131,7 +131,7 @@ exception
    when E : GPRtools.Usage_Error =>
       Text_IO.Put_Line
         (Text_IO.Standard_Error,
-         "gprdoc: " & Exception_Message (E));
+         "gpr2doc: " & Exception_Message (E));
       GPRtools.Command_Line.Try_Help;
       GPRtools.Util.Exit_Program (GPRtools.Util.E_Fatal);
 
