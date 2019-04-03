--- lib/Driver/ToolChains/Gnu.cpp.orig	2019-01-15 21:04:36 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -400,6 +400,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -490,6 +493,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (Args.hasArg(options::OPT_static))
         CmdArgs.push_back("--start-group");
 
