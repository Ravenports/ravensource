--- tools/clang/lib/Driver/ToolChains/Gnu.cpp.orig	2017-12-09 00:34:01 UTC
+++ tools/clang/lib/Driver/ToolChains/Gnu.cpp
@@ -396,6 +396,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -483,6 +486,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (Args.hasArg(options::OPT_static))
         CmdArgs.push_back("--start-group");
 
