--- lib/Driver/ToolChains/DragonFly.cpp.orig	2025-05-13 22:18:22 UTC
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
@@ -121,18 +121,38 @@ void dragonfly::Linker::ConstructJob(Com
     CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath(crtbegin)));
   }
 
+  if (D.isUsingLTO()) {
+    assert(!Inputs.empty() && "Must have at least one input.");
+    // Find the first filename InputInfo object.
+    auto Input = llvm::find_if(
+        Inputs, [](const InputInfo &II) -> bool { return II.isFilename(); });
+    if (Input == Inputs.end())
+      // For a very rare case, all of the inputs to the linker are
+      // InputArg. If that happens, just use the first InputInfo.
+      Input = Inputs.begin();
+
+    addLTOOptions(ToolChain, Args, CmdArgs, Output, *Input,
+                  D.getLTOMode() == LTOK_Thin);
+  }
+
   Args.addAllArgs(CmdArgs, {options::OPT_L, options::OPT_T_Group,
                             options::OPT_s, options::OPT_t});
   ToolChain.AddFilePathLibArgs(Args, CmdArgs);
 
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
@@ -168,16 +188,7 @@ void dragonfly::Linker::ConstructJob(Com
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
 
@@ -211,7 +222,8 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib"));
-  getFilePaths().push_back(concat(getDriver().SysRoot, "/usr/lib/gcc80"));
+  getFilePaths().push_back(concat(getDriver().SysRoot, "@RAVEN_GCC@"));
+  getFilePaths().push_back(concat(getDriver().SysRoot, "@RAVEN_GCC_TARGET@"));
 }
 
 void DragonFly::AddClangSystemIncludeArgs(
@@ -237,8 +249,9 @@ void DragonFly::AddClangSystemIncludeArg
 
 void DragonFly::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                          llvm::opt::ArgStringList &CC1Args) const {
-  addLibStdCXXIncludePaths(concat(getDriver().SysRoot, "/usr/include/c++/8.0"), "", "",
-                           DriverArgs, CC1Args);
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/@RAVEN_TRIPLE@");
 }
 
 Tool *DragonFly::buildAssembler() const {
@@ -248,3 +261,5 @@ Tool *DragonFly::buildAssembler() const
 Tool *DragonFly::buildLinker() const {
   return new tools::dragonfly::Linker(*this);
 }
+
+bool DragonFly::HasNativeLLVMSupport() const { return true; }
