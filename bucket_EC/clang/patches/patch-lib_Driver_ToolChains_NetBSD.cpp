--- lib/Driver/ToolChains/NetBSD.cpp.orig	2023-11-28 08:52:28 UTC
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -265,10 +265,15 @@ void netbsd::Linker::ConstructJob(Compil
   bool NeedsXRayDeps = addXRayRuntime(ToolChain, Args, CmdArgs);
   AddLinkerInputs(ToolChain, Inputs, Args, CmdArgs, JA);
 
-  const SanitizerArgs &SanArgs = ToolChain.getSanitizerArgs(Args);
-  if (SanArgs.needsSharedRt()) {
+  CmdArgs.push_back("-L@RAVEN_GCC_TARGET@");
+  CmdArgs.push_back("-L@RAVEN_GCC@");
+  CmdArgs.push_back("-L@LOCALBASE@/lib");
+
+  if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
     CmdArgs.push_back("-rpath");
-    CmdArgs.push_back(Args.MakeArgString(ToolChain.getCompilerRTPath()));
+    CmdArgs.push_back("@LOCALBASE@/lib");
   }
 
   bool useLibgcc = true;
@@ -286,7 +291,6 @@ void netbsd::Linker::ConstructJob(Compil
   case llvm::Triple::sparcv9:
   case llvm::Triple::x86:
   case llvm::Triple::x86_64:
-    useLibgcc = false;
     break;
   default:
     break;
@@ -310,21 +314,20 @@ void netbsd::Linker::ConstructJob(Compil
       linkXRayRuntimeDeps(ToolChain, CmdArgs);
     if (Args.hasArg(options::OPT_pthread))
       CmdArgs.push_back("-lpthread");
-    CmdArgs.push_back("-lc");
+    if (!Args.hasArg(options::OPT_nolibc)) {
+      CmdArgs.push_back("-lc");
+    }
 
     if (useLibgcc) {
-      if (Args.hasArg(options::OPT_static)) {
+      if (Args.hasArg(options::OPT_static) ||
+          Args.hasArg(options::OPT_static_libgcc)) {
         // libgcc_eh depends on libc, so resolve as much as possible,
         // pull in any new requirements from libc and then get the rest
         // of libgcc.
-        CmdArgs.push_back("-lgcc_eh");
-        CmdArgs.push_back("-lc");
         CmdArgs.push_back("-lgcc");
+        CmdArgs.push_back("-lgcc_eh");
       } else {
-        CmdArgs.push_back("-lgcc");
-        CmdArgs.push_back("--as-needed");
         CmdArgs.push_back("-lgcc_s");
-        CmdArgs.push_back("--no-as-needed");
       }
     }
   }
@@ -408,24 +411,6 @@ Tool *NetBSD::buildAssembler() const {
 Tool *NetBSD::buildLinker() const { return new tools::netbsd::Linker(*this); }
 
 ToolChain::CXXStdlibType NetBSD::GetDefaultCXXStdlibType() const {
-  switch (getArch()) {
-  case llvm::Triple::aarch64:
-  case llvm::Triple::aarch64_be:
-  case llvm::Triple::arm:
-  case llvm::Triple::armeb:
-  case llvm::Triple::thumb:
-  case llvm::Triple::thumbeb:
-  case llvm::Triple::ppc:
-  case llvm::Triple::ppc64:
-  case llvm::Triple::ppc64le:
-  case llvm::Triple::sparc:
-  case llvm::Triple::sparcv9:
-  case llvm::Triple::x86:
-  case llvm::Triple::x86_64:
-    return ToolChain::CST_Libcxx;
-  default:
-    break;
-  }
   return ToolChain::CST_Libstdcxx;
 }
 
@@ -486,8 +471,9 @@ void NetBSD::addLibCxxIncludePaths(const
 
 void NetBSD::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                       llvm::opt::ArgStringList &CC1Args) const {
-  addLibStdCXXIncludePaths(getDriver().SysRoot + "/usr/include/g++", "", "",
-                           DriverArgs, CC1Args);
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/@RAVEN_TRIPLE@");
 }
 
 llvm::ExceptionHandling NetBSD::GetExceptionModel(const ArgList &Args) const {
