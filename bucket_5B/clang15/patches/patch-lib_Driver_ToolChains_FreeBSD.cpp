--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2022-10-18 06:29:45 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -296,6 +296,16 @@ void freebsd::Linker::ConstructJob(Compi
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
@@ -393,12 +403,11 @@ FreeBSD::FreeBSD(const Driver &D, const
     getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib32"));
   else
     getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib"));
+    getFilePaths().push_back("@RAVEN_GCC@");
+    getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 ToolChain::CXXStdlibType FreeBSD::GetDefaultCXXStdlibType() const {
-  unsigned Major = getTriple().getOSMajorVersion();
-  if (Major >= 10 || Major == 0)
-    return ToolChain::CST_Libcxx;
   return ToolChain::CST_Libstdcxx;
 }
 
