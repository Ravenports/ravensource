--- source/ada/lsp-ada_handlers.adb.orig	2021-06-09 23:01:34 UTC
+++ source/ada/lsp-ada_handlers.adb
@@ -52,7 +52,7 @@ with LSP.Types;        use LSP.Types;
 with Langkit_Support.Slocs;
 with Langkit_Support.Text;
 
-with Laltools.Common;
+with Laltools.Common; use Laltools.Common;
 with Laltools.Refactor_Imports;
 with Laltools.Refactor.Subprogram_Signature;
 with Laltools.Refactor.Safe_Rename;
