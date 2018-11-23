--- lib/Driver/ToolChains/Gnu.cpp.orig	2018-07-31 14:21:46 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -378,6 +378,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -468,6 +471,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (Args.hasArg(options::OPT_static))
         CmdArgs.push_back("--start-group");
 
