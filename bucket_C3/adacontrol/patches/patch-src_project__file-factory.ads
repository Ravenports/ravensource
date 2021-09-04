When adacontrol can build with the ravenports base compiler
delete this patch.

--- src/project_file-factory.ads.orig	2019-10-30 08:19:42 UTC
+++ src/project_file-factory.ads
@@ -36,10 +36,10 @@
 
 -- To have full support of GNAT .gpr project files,
 -- uncomment the following lines :
-with Project_File.Factory_Full;
-package Project_File.Factory renames Project_File.Factory_Full;
+-- with Project_File.Factory_Full;
+-- package Project_File.Factory renames Project_File.Factory_Full;
 
 -- To have support of .adp project files only (no GNAT .gpr project files, saves dependence on GnatColl),
 -- uncomment the following lines :
---  with Project_File.Factory_No_Gpr;
---  package Project_File.Factory renames Project_File.Factory_No_Gpr;
+with Project_File.Factory_No_Gpr;
+package Project_File.Factory renames Project_File.Factory_No_Gpr;
