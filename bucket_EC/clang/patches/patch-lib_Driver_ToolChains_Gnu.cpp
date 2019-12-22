--- lib/Driver/ToolChains/Gnu.cpp.orig	2019-12-11 19:15:30 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -442,6 +442,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!IsStatic) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -543,6 +546,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
