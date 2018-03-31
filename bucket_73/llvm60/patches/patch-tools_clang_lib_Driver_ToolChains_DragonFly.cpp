--- tools/clang/lib/Driver/ToolChains/DragonFly.cpp.orig	2017-07-25 18:02:57 UTC
+++ tools/clang/lib/Driver/ToolChains/DragonFly.cpp
@@ -70,7 +70,7 @@ void dragonfly::Linker::ConstructJob(Com
       CmdArgs.push_back("-Bshareable");
     else {
       CmdArgs.push_back("-dynamic-linker");
-      CmdArgs.push_back("/usr/libexec/ld-elf.so.2");
+      CmdArgs.push_back("/libexec/ld-elf.so.2");
     }
     CmdArgs.push_back("--hash-style=gnu");
     CmdArgs.push_back("--enable-new-dtags");
@@ -113,17 +113,20 @@ void dragonfly::Linker::ConstructJob(Com
           Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
   }
 
+  if (D.isUsingLTO())
+    AddGoldPlugin(getToolChain(), Args, CmdArgs, D.getLTOMode() == LTOK_Thin, D);
+
   Args.AddAllArgs(CmdArgs,
                   {options::OPT_L, options::OPT_T_Group, options::OPT_e});
 
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs, JA);
 
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
-    CmdArgs.push_back("-L/usr/lib/gcc50");
+    CmdArgs.push_back("-L@RAVEN_GCC@");
 
     if (!Args.hasArg(options::OPT_static)) {
       CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib/gcc50");
+      CmdArgs.push_back("@RAVEN_GCC@");
     }
 
     if (D.CCCIsCXX()) {
@@ -144,16 +147,7 @@ void dragonfly::Linker::ConstructJob(Com
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
 
@@ -186,7 +180,8 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back("/usr/lib");
-  getFilePaths().push_back("/usr/lib/gcc50");
+  getFilePaths().push_back("@RAVEN_GCC@");
+  getFilePaths().push_back("@RAVEN_GCC_TARGET@");
 }
 
 Tool *DragonFly::buildAssembler() const {
@@ -196,3 +191,5 @@ Tool *DragonFly::buildAssembler() const
 Tool *DragonFly::buildLinker() const {
   return new tools::dragonfly::Linker(*this);
 }
+
+bool DragonFly::HasNativeLLVMSupport() const { return true; }
