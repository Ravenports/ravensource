--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2022-01-20 21:31:59 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -293,6 +293,16 @@ void freebsd::Linker::ConstructJob(Compi
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
   bool Profiling = Args.hasArg(options::OPT_pg) &&
                    ToolChain.getTriple().getOSMajorVersion() < 14;
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
@@ -388,11 +398,11 @@ FreeBSD::FreeBSD(const Driver &D, const
     getFilePaths().push_back(getDriver().SysRoot + "/usr/lib32");
   else
     getFilePaths().push_back(getDriver().SysRoot + "/usr/lib");
+    getFilePaths().push_back("@RAVEN_GCC@");
+    getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 ToolChain::CXXStdlibType FreeBSD::GetDefaultCXXStdlibType() const {
-  if (getTriple().getOSMajorVersion() >= 10)
-    return ToolChain::CST_Libcxx;
   return ToolChain::CST_Libstdcxx;
 }
 
