--- lib/Driver/ToolChains/Gnu.cpp.orig	2020-07-07 16:21:37 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -444,6 +444,9 @@ void tools::gnutools::Linker::ConstructJ
   }
 
   if (!IsStatic) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -545,6 +548,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
