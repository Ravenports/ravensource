--- code_analysis/src/code_analysis_module.adb.orig	2023-05-10 09:41:12 UTC
+++ code_analysis/src/code_analysis_module.adb
@@ -2463,6 +2463,7 @@ package body Code_Analysis_Module is
    is
       Root : Node_Ptr;
       Success_1, Success_2 : Boolean;
+      pragma Unreferenced (Success_1, Success_2);
    begin
       Root     := new XML_Utils.Node;
       Root.Tag := new String'("Code_Analysis_Tree");
