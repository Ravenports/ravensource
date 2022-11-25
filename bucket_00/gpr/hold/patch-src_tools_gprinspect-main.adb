--- src/tools/gprinspect-main.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprinspect-main.adb
@@ -111,7 +111,7 @@ procedure GPRinspect.Main is
                     Allow_Quiet      => False);
       Group  : constant GPRtools.Command_Line.Argument_Group :=
                  Parser.Add_Argument_Group
-                   ("gprinspect", On_Switch'Unrestricted_Access);
+                   ("gpr2inspect", On_Switch'Unrestricted_Access);
 
    begin
       Setup (Tool => GPRtools.Inspect);
@@ -166,7 +166,7 @@ begin
 
    --  Set program name
 
-   GPRtools.Util.Set_Program_Name ("gprinspect");
+   GPRtools.Util.Set_Program_Name ("gpr2inspect");
 
    --  Run the GPRinspect main procedure depending on command line options
 
@@ -177,7 +177,7 @@ exception
    when E : GPRtools.Usage_Error =>
       Text_IO.Put_Line
         (Text_IO.Standard_Error,
-         "gprinspect: " & Exception_Message (E));
+         "gpr2inspect: " & Exception_Message (E));
       GPRtools.Command_Line.Try_Help;
       GPRtools.Util.Exit_Program (GPRtools.Util.E_Fatal);
 
