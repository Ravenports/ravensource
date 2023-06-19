--- lib/Driver/ToolChains/Gnu.cpp.orig	2023-06-10 22:58:16 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -480,6 +480,9 @@ void tools::gnutools::Linker::ConstructJ
   if (IsStatic) {
     CmdArgs.push_back("-static");
   } else {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -603,6 +606,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_r)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
