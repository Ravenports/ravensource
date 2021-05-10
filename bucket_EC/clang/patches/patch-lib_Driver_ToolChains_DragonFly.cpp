--- lib/Driver/ToolChains/DragonFly.cpp.orig	2021-04-06 16:38:18 UTC
+++ lib/Driver/ToolChains/DragonFly.cpp
@@ -71,7 +71,7 @@ void dragonfly::Linker::ConstructJob(Com
       CmdArgs.push_back("-Bshareable");
     else {
       CmdArgs.push_back("-dynamic-linker");
-      CmdArgs.push_back("/usr/libexec/ld-elf.so.2");
+      CmdArgs.push_back("/libexec/ld-elf.so.2");
     }
     CmdArgs.push_back("--hash-style=gnu");
     CmdArgs.push_back("--enable-new-dtags");
@@ -114,19 +114,28 @@ void dragonfly::Linker::ConstructJob(Com
           Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
   }
 
+  if (D.isUsingLTO()) {
+    assert(!Inputs.empty() && "Must have at least one input.");
+    addLTOOptions(getToolChain(), Args, CmdArgs, Output, Inputs[0],
+                  D.getLTOMode() == LTOK_Thin);
+  }
+
   Args.AddAllArgs(CmdArgs,
                   {options::OPT_L, options::OPT_T_Group, options::OPT_e});
 
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs, JA);
 
-  if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
-    CmdArgs.push_back("-L/usr/lib/gcc80");
+  CmdArgs.push_back("-L@RAVEN_GCC@");
+  CmdArgs.push_back("-L@LOCALBASE@/lib");
 
-    if (!Args.hasArg(options::OPT_static)) {
-      CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib/gcc80");
-    }
+  if (!Args.hasArg(options::OPT_static)) {
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@RAVEN_GCC@");
+    CmdArgs.push_back("-rpath");
+    CmdArgs.push_back("@LOCALBASE@/lib");
+  }
 
+  if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
     if (D.CCCIsCXX()) {
       if (getToolChain().ShouldLinkCXXStdlib(Args))
         getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
@@ -145,16 +154,7 @@ void dragonfly::Linker::ConstructJob(Com
         CmdArgs.push_back("-lgcc");
         CmdArgs.push_back("-lgcc_eh");
     } else {
-      if (Args.hasArg(options::OPT_shared_libgcc)) {
-          CmdArgs.push_back("-lgcc_pic");
-          if (!Args.hasArg(options::OPT_shared))
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
 
@@ -189,7 +189,8 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back("/usr/lib");
-  getFilePaths().push_back("/usr/lib/gcc80");
+  getFilePaths().push_back("@RAVEN_GCC@");
+  getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 Tool *DragonFly::buildAssembler() const {
@@ -199,3 +200,5 @@ Tool *DragonFly::buildAssembler() const
 Tool *DragonFly::buildLinker() const {
   return new tools::dragonfly::Linker(*this);
 }
+
+bool DragonFly::HasNativeLLVMSupport() const { return true; }
