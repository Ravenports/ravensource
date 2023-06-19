--- lib/Driver/ToolChains/DragonFly.cpp.orig	2023-06-10 22:58:16 UTC
+++ lib/Driver/ToolChains/DragonFly.cpp
@@ -71,7 +71,7 @@ void dragonfly::Linker::ConstructJob(Com
       CmdArgs.push_back("-Bshareable");
     else if (!Args.hasArg(options::OPT_r)) {
       CmdArgs.push_back("-dynamic-linker");
-      CmdArgs.push_back("/usr/libexec/ld-elf.so.2");
+      CmdArgs.push_back("/libexec/ld-elf.so.2");
     }
     CmdArgs.push_back("--hash-style=gnu");
     CmdArgs.push_back("--enable-new-dtags");
@@ -115,19 +115,29 @@ void dragonfly::Linker::ConstructJob(Com
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
-    CmdArgs.push_back("-L/usr/lib/gcc80");
-
-    if (!Args.hasArg(options::OPT_static)) {
-      CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib/gcc80");
-    }
 
     if (D.CCCIsCXX()) {
       if (getToolChain().ShouldLinkCXXStdlib(Args))
@@ -147,16 +157,7 @@ void dragonfly::Linker::ConstructJob(Com
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
 
@@ -192,7 +193,8 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back("/usr/lib");
-  getFilePaths().push_back("/usr/lib/gcc80");
+  getFilePaths().push_back("@RAVEN_GCC@");
+  getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 Tool *DragonFly::buildAssembler() const {
@@ -202,3 +204,5 @@ Tool *DragonFly::buildAssembler() const
 Tool *DragonFly::buildLinker() const {
   return new tools::dragonfly::Linker(*this);
 }
+
+bool DragonFly::HasNativeLLVMSupport() const { return true; }
