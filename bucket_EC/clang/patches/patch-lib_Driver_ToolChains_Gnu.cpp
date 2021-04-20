--- lib/Driver/ToolChains/Gnu.cpp.orig	2021-04-06 16:38:18 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -482,6 +482,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!IsStatic) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -588,6 +591,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
