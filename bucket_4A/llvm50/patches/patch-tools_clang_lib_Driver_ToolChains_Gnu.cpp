--- tools/clang/lib/Driver/ToolChains/Gnu.cpp.orig	2017-08-11 01:47:32 UTC
+++ tools/clang/lib/Driver/ToolChains/Gnu.cpp
@@ -489,6 +489,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -574,6 +577,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (Args.hasArg(options::OPT_static))
         CmdArgs.push_back("--start-group");
 
