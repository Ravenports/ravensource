--- tools/clang/lib/Driver/Tools.cpp.orig	2017-06-23 13:14:28 UTC
+++ tools/clang/lib/Driver/Tools.cpp
@@ -10140,6 +10140,9 @@ void gnutools::Linker::ConstructJob(Comp
   }
 
   if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
 
@@ -10225,6 +10228,8 @@ void gnutools::Linker::ConstructJob(Comp
 
   if (!Args.hasArg(options::OPT_nostdlib)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (Args.hasArg(options::OPT_static))
         CmdArgs.push_back("--start-group");
 
