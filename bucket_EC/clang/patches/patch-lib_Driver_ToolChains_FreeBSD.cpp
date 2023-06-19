--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2023-06-10 22:58:16 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -286,6 +286,16 @@ void freebsd::Linker::ConstructJob(Compi
   addLinkerCompressDebugSectionsOption(ToolChain, Args, CmdArgs);
   AddLinkerInputs(ToolChain, Inputs, Args, CmdArgs, JA);
 
+  CmdArgs.push_back("-L@RAVEN_GCC@");
+  CmdArgs.push_back("-L@LOCALBASE@/lib");
+
+  if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@LOCALBASE@/lib");
+  }
+
   unsigned Major = ToolChain.getTriple().getOSMajorVersion();
   bool Profiling = Args.hasArg(options::OPT_pg) && Major != 0 && Major < 14;
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs,
@@ -383,6 +393,8 @@ FreeBSD::FreeBSD(const Driver &D, const
     getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib32"));
   else
     getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib"));
+    getFilePaths().push_back("@RAVEN_GCC@");
+    getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 unsigned FreeBSD::GetDefaultDwarfVersion() const {
