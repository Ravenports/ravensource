--- src/tools/gprtools-util.adb.orig	2022-09-22 17:09:03 UTC
+++ src/tools/gprtools-util.adb
@@ -321,9 +321,9 @@ package body GPRtools.Util is
       if Value (GPR_Tool, Default => "") = "" then
          Set
            (GPR_Tool,
-            (if Name in "gprclean" | "gprbuild" | "gprls" | "gprname"
-                 | "gprinstall" | "gprdump" | "gprdoc"
-             then "gprbuild"
+            (if Name in "gpr2clean" | "gpr2build" | "gpr2ls" | "gpr2name"
+                 | "gpr2install" | "gpr2dump" | "gpr2doc"
+             then "gpr2build"
              else Name));
       end if;
    end Set_Program_Name;
