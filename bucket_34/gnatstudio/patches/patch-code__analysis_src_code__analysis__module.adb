--- code_analysis/src/code_analysis_module.adb.orig	2022-05-11 12:25:42 UTC
+++ code_analysis/src/code_analysis_module.adb
@@ -2288,6 +2288,7 @@ package body Code_Analysis_Module is
    is
       Root : Node_Ptr;
       Success_1, Success_2 : Boolean;
+      pragma Unreferenced (Success_1, Success_2);
    begin
       Root     := new XML_Utils.Node;
       Root.Tag := new String'("Code_Analysis_Tree");
