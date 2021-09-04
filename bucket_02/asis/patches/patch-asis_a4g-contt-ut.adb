--- asis/a4g-contt-ut.adb.orig	2020-02-29 15:19:01 UTC
+++ asis/a4g-contt-ut.adb
@@ -1965,7 +1965,7 @@ package body A4G.Contt.UT is
       if Present (Config_Pragmas (Next_Conf_Pragma)) then
          Next_Conf_Pragma := First (Config_Pragmas (Next_Conf_Pragma));
       else
-         Next_Conf_Pragma := Empty;
+         Next_Conf_Pragma := Types.Empty;
       end if;
 
       while Present (Next_Conf_Pragma) loop
