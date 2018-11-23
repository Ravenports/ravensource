--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2018-07-10 17:44:08 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -263,6 +263,11 @@ void freebsd::Linker::ConstructJob(Compi
   AddLinkerInputs(ToolChain, Inputs, Args, CmdArgs, JA);
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
+    CmdArgs.push_back("-L@RAVEN_GCC@");
+    if (!Args.hasArg(options::OPT_static)) {
+      CmdArgs.push_back("-rpath");
+      CmdArgs.push_back("@RAVEN_GCC@");
+    }
     addOpenMPRuntime(CmdArgs, ToolChain, Args);
     if (D.CCCIsCXX()) {
       if (ToolChain.ShouldLinkCXXStdlib(Args))
@@ -349,11 +354,11 @@ FreeBSD::FreeBSD(const Driver &D, const
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
 
