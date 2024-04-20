--- lib/Driver/ToolChains/Gnu.cpp.orig	2024-04-17 00:21:15 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -439,6 +439,9 @@ void tools::gnutools::Linker::ConstructJ
   } else if (IsStatic) {
     CmdArgs.push_back("-static");
   } else if (!Args.hasArg(options::OPT_r)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
     if (!IsShared) {
@@ -576,6 +579,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_r)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
