--- lib/Driver/ToolChains/Gnu.cpp.orig	2023-11-28 08:52:28 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -461,6 +461,9 @@ void tools::gnutools::Linker::ConstructJ
   if (IsStatic) {
     CmdArgs.push_back("-static");
   } else {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -584,6 +587,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_r)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
