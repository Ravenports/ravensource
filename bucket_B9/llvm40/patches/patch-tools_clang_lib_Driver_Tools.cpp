--- tools/clang/lib/Driver/Tools.cpp.orig	2017-04-22 17:20:27 UTC
+++ tools/clang/lib/Driver/Tools.cpp
@@ -3222,13 +3222,13 @@ static void addOpenMPRuntime(ArgStringLi
 
   switch (TC.getDriver().getOpenMPRuntime(Args)) {
   case Driver::OMPRT_OMP:
-    CmdArgs.push_back("-lomp");
+    CmdArgs.push_back("/usr/local/llvm40/lib/libomp.so");
     break;
   case Driver::OMPRT_GOMP:
-    CmdArgs.push_back("-lgomp");
+    CmdArgs.push_back("/usr/local/llvm40/lib/libgomp.so");
     break;
   case Driver::OMPRT_IOMP5:
-    CmdArgs.push_back("-liomp5");
+    CmdArgs.push_back("/usr/local/llvm40/lib/libiomp5.so");
     break;
   case Driver::OMPRT_Unknown:
     // Already diagnosed.
@@ -10246,17 +10246,15 @@ void gnutools::Linker::ConstructJob(Comp
         // Also link the particular OpenMP runtimes.
         switch (ToolChain.getDriver().getOpenMPRuntime(Args)) {
         case Driver::OMPRT_OMP:
-          CmdArgs.push_back("-lomp");
+          CmdArgs.push_back("/usr/local/llvm40/lib/libomp.so");
           break;
         case Driver::OMPRT_GOMP:
-          CmdArgs.push_back("-lgomp");
-
-          // FIXME: Exclude this for platforms with libgomp that don't require
-          // librt. Most modern Linux platforms require it, but some may not.
-          CmdArgs.push_back("-lrt");
+          CmdArgs.push_back("/usr/local/llvm40/lib/libgomp.so");
+          if (ToolChain.getTriple().getOS() == llvm::Triple::Linux)
+             CmdArgs.push_back("-lrt");
           break;
         case Driver::OMPRT_IOMP5:
-          CmdArgs.push_back("-liomp5");
+          CmdArgs.push_back("/usr/local/llvm40/lib/libiomp5.so");
           break;
         case Driver::OMPRT_Unknown:
           // Already diagnosed.
