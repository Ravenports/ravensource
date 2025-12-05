--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2025-12-01 12:58:50 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -281,6 +281,16 @@ void freebsd::Linker::ConstructJob(Compi
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
@@ -397,6 +407,8 @@ FreeBSD::FreeBSD(const Driver &D, const
     getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib32"));
   else
     getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib"));
+    getFilePaths().push_back("@RAVEN_GCC@");
+    getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 void FreeBSD::AddClangSystemIncludeArgs(
@@ -433,23 +445,19 @@ void FreeBSD::AddClangSystemIncludeArgs(
                           concat(D.SysRoot, "/usr/include"));
 }
 
+void FreeBSD::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
+                                    llvm::opt::ArgStringList &CC1Args) const {
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/@RAVEN_TRIPLE@");
+}
+
 void FreeBSD::addLibCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                     llvm::opt::ArgStringList &CC1Args) const {
   addSystemInclude(DriverArgs, CC1Args,
                    concat(getDriver().SysRoot, "/usr/include/c++/v1"));
 }
 
-void FreeBSD::AddCXXStdlibLibArgs(const ArgList &Args,
-                                  ArgStringList &CmdArgs) const {
-  Generic_ELF::AddCXXStdlibLibArgs(Args, CmdArgs);
-  unsigned Major = getTriple().getOSMajorVersion();
-  bool SuffixedLib = Args.hasArg(options::OPT_pg) && Major != 0 && Major < 14;
-  if (SuffixedLib && GetCXXStdlibType(Args) == CST_Libcxx)
-    std::replace_if(
-        CmdArgs.begin(), CmdArgs.end(),
-        [](const char *S) { return StringRef(S) == "-lc++"; }, "-lc++_p");
-}
-
 void FreeBSD::AddCudaIncludeArgs(const ArgList &DriverArgs,
                                  ArgStringList &CC1Args) const {
   CudaInstallation->AddCudaIncludeArgs(DriverArgs, CC1Args);
