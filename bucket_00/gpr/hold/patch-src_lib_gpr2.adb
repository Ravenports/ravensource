--- src/lib/gpr2.adb.orig	2022-09-22 17:09:03 UTC
+++ src/lib/gpr2.adb
@@ -62,7 +62,7 @@ package body GPR2 is
       use type GNAT.OS_Lib.String_Access;
 
       GPRls : GNAT.OS_Lib.String_Access :=
-                GNAT.OS_Lib.Locate_Exec_On_Path ("gprls");
+                GNAT.OS_Lib.Locate_Exec_On_Path ("gpr2ls");
       --  Check for GPRls executable
    begin
       if GPRls = null then
