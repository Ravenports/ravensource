--- source/ada/lsp-ada_handlers-refactor_remove_parameter.ads.orig	2021-06-09 23:01:34 UTC
+++ source/ada/lsp-ada_handlers-refactor_remove_parameter.ads
@@ -26,6 +26,7 @@ with LSP.JSON_Streams;
 
 with Libadalang.Analysis;
 
+with Laltools.Common; use Laltools.Common;
 with Laltools.Refactor.Subprogram_Signature;
 use Laltools.Refactor.Subprogram_Signature;
 
