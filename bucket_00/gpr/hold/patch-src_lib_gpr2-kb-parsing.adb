--- src/lib/gpr2-kb-parsing.adb.orig	2022-09-22 17:09:03 UTC
+++ src/lib/gpr2-kb-parsing.adb
@@ -1460,7 +1460,7 @@ package body GPR2.KB.Parsing is
       N : Node;
 
    begin
-      if Node_Name (Root_Node) = "gprconfig" then
+      if Node_Name (Root_Node) = "gpr2config" then
          N := First_Child (Root_Node);
 
          while N /= null loop
