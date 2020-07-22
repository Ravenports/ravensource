--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2020-07-07 16:21:37 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -284,6 +284,16 @@ void freebsd::Linker::ConstructJob(Compi
   bool NeedsXRayDeps = addXRayRuntime(ToolChain, Args, CmdArgs);
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
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
     // Use the static OpenMP runtime with -static-openmp
     bool StaticOpenMP = Args.hasArg(options::OPT_static_openmp) &&
@@ -375,11 +385,11 @@ FreeBSD::FreeBSD(const Driver &D, const
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
 
