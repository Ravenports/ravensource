--- lib/Driver/ToolChains/NetBSD.cpp.orig	2023-06-10 22:58:16 UTC
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -266,10 +266,15 @@ void netbsd::Linker::ConstructJob(Compil
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
 
   VersionTuple OsVersion = Triple.getOSVersion();
@@ -289,7 +294,6 @@ void netbsd::Linker::ConstructJob(Compil
     case llvm::Triple::sparcv9:
     case llvm::Triple::x86:
     case llvm::Triple::x86_64:
-      useLibgcc = false;
       break;
     default:
       break;
@@ -314,21 +318,20 @@ void netbsd::Linker::ConstructJob(Compil
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
@@ -428,7 +431,7 @@ ToolChain::CXXStdlibType NetBSD::GetDefa
     case llvm::Triple::sparcv9:
     case llvm::Triple::x86:
     case llvm::Triple::x86_64:
-      return ToolChain::CST_Libcxx;
+      return ToolChain::CST_Libstdcxx;
     default:
       break;
     }
@@ -493,8 +496,6 @@ void NetBSD::addLibCxxIncludePaths(const
 
 void NetBSD::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                       llvm::opt::ArgStringList &CC1Args) const {
-  addLibStdCXXIncludePaths(getDriver().SysRoot + "/usr/include/g++", "", "",
-                           DriverArgs, CC1Args);
 }
 
 llvm::ExceptionHandling NetBSD::GetExceptionModel(const ArgList &Args) const {
