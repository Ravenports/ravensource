--- lib/Driver/ToolChains/DragonFly.cpp.orig	2026-10-19 23:57:12 UTC
+++ lib/Driver/ToolChains/DragonFly.cpp
@@ -76,7 +76,7 @@ void dragonfly::Linker::ConstructJob(Com
       CmdArgs.push_back("-shared");
     else if (!Args.hasArg(options::OPT_r)) {
       CmdArgs.push_back("-dynamic-linker");
-      CmdArgs.push_back("/usr/libexec/ld-elf.so.2");
+      CmdArgs.push_back("/libexec/ld-elf.so.2");
     }
     CmdArgs.push_back("--hash-style=gnu");
     CmdArgs.push_back("--enable-new-dtags");
@@ -125,14 +125,23 @@ void dragonfly::Linker::ConstructJob(Com
                             options::OPT_s, options::OPT_t});
   ToolChain.AddFilePathLibArgs(Args, CmdArgs);
 
+  if (auto LTO = ToolChain.getLTOMode(Args); LTO != LTOK_None)
+    addLTOOptions(ToolChain, Args, CmdArgs, Output, Inputs, LTO == LTOK_Thin);
+
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
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs,
                    options::OPT_r)) {
-    if (!Static) {
-      CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib/gcc80");
-    }
 
     // Use the static OpenMP runtime with -static-openmp
     bool StaticOpenMP = Args.hasArg(options::OPT_static_openmp) && !Static;
@@ -168,16 +177,7 @@ void dragonfly::Linker::ConstructJob(Com
         CmdArgs.push_back("-lgcc");
         CmdArgs.push_back("-lgcc_eh");
     } else {
-      if (Args.hasArg(options::OPT_shared_libgcc)) {
-          CmdArgs.push_back("-lgcc_pic");
-          if (!Shared)
-            CmdArgs.push_back("-lgcc");
-      } else {
-          CmdArgs.push_back("-lgcc");
-          CmdArgs.push_back("--as-needed");
-          CmdArgs.push_back("-lgcc_pic");
-          CmdArgs.push_back("--no-as-needed");
-      }
+      CmdArgs.push_back("-lgcc_s");
     }
   }
 
@@ -211,7 +211,8 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib"));
-  getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib/gcc80"));
+  getFilePaths().push_back(concat(getDriver().SysRoot, "@RAVEN_GCC@"));
+  getFilePaths().push_back(concat(getDriver().SysRoot, "@RAVEN_GCC_TARGET@"));
 }
 
 void DragonFly::AddClangSystemIncludeArgs(
@@ -237,8 +238,9 @@ void DragonFly::AddClangSystemIncludeArg
 
 void DragonFly::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                          llvm::opt::ArgStringList &CC1Args) const {
-  addLibStdCXXIncludePaths(concat(getDriver().SysRoot, "/usr/include/c++/8.0"), "", "",
-                           DriverArgs, CC1Args);
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/@RAVEN_TRIPLE@");
 }
 
 Tool *DragonFly::buildAssembler() const {
@@ -248,3 +250,5 @@ Tool *DragonFly::buildAssembler() const
 Tool *DragonFly::buildLinker() const {
   return new tools::dragonfly::Linker(*this);
 }
+
+bool DragonFly::HasNativeLLVMSupport() const { return true; }
