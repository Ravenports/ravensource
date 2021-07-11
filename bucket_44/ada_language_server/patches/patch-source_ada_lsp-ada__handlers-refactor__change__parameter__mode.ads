--- source/ada/lsp-ada_handlers-refactor_change_parameter_mode.ads.orig	2021-06-09 23:01:34 UTC
+++ source/ada/lsp-ada_handlers-refactor_change_parameter_mode.ads
@@ -27,6 +27,7 @@ with LSP.JSON_Streams;
 with Libadalang.Analysis;
 with Libadalang.Common;
 
+with Laltools.Common; use Laltools.Common;
 with Laltools.Refactor.Subprogram_Signature;
 use Laltools.Refactor.Subprogram_Signature;
 
