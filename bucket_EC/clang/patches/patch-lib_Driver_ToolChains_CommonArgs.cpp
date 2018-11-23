--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2018-06-26 16:14:35 UTC
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -499,16 +499,16 @@ bool tools::addOpenMPRuntime(ArgStringLi
 
   switch (TC.getDriver().getOpenMPRuntime(Args)) {
   case Driver::OMPRT_OMP:
-    CmdArgs.push_back("-lomp");
+    CmdArgs.push_back("/usr/local/llvm50/lib/libomp.so");
     break;
   case Driver::OMPRT_GOMP:
-    CmdArgs.push_back("-lgomp");
+    CmdArgs.push_back("/usr/local/llvm50/lib/libgomp.so");
 
     if (GompNeedsRT)
       CmdArgs.push_back("-lrt");
     break;
   case Driver::OMPRT_IOMP5:
-    CmdArgs.push_back("-liomp5");
+    CmdArgs.push_back("/usr/local/llvm50/lib/libiomp5.so");
     break;
   case Driver::OMPRT_Unknown:
     // Already diagnosed.
