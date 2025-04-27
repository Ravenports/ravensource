--- lib/Driver/ToolChains/Gnu.cpp.orig	2024-10-29 10:09:39 UTC
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -443,6 +443,11 @@ void tools::gnutools::Linker::ConstructJ
   } else if (IsStatic) {
     CmdArgs.push_back("-static");
   } else if (!Args.hasArg(options::OPT_r)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@LOCALBASE@/lib");
+
     if (Args.hasArg(options::OPT_rdynamic))
       CmdArgs.push_back("-export-dynamic");
     if (!IsShared) {
@@ -580,6 +585,8 @@ void tools::gnutools::Linker::ConstructJ
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_r)) {
     if (!Args.hasArg(options::OPT_nodefaultlibs)) {
+      CmdArgs.push_back("-L@RAVEN_GCC@");
+
       if (IsStatic || IsStaticPIE)
         CmdArgs.push_back("--start-group");
 
@@ -3056,6 +3063,8 @@ Generic_GCC::Generic_GCC(const Driver &D
     : ToolChain(D, Triple, Args), GCCInstallation(D),
       CudaInstallation(D, Triple, Args), RocmInstallation(D, Triple, Args) {
   getProgramPaths().push_back(getDriver().Dir);
+  getFilePaths().push_back(concat(getDriver().SysRoot, "@RAVEN_GCC@"));
+  getFilePaths().push_back(concat(getDriver().SysRoot, "@RAVEN_GCC_TARGET@"));
 }
 
 Generic_GCC::~Generic_GCC() {}
@@ -3422,10 +3431,9 @@ bool Generic_GCC::addGCCLibStdCxxInclude
 void
 Generic_GCC::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                       llvm::opt::ArgStringList &CC1Args) const {
-  if (GCCInstallation.isValid()) {
-    addGCCLibStdCxxIncludePaths(DriverArgs, CC1Args,
-                                GCCInstallation.getTriple().str());
-  }
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/@RAVEN_TRIPLE@");
 }
 
 llvm::opt::DerivedArgList *
