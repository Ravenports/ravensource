--- tools/clang/lib/Driver/ToolChains.cpp.orig	2017-01-10 21:13:08 UTC
+++ tools/clang/lib/Driver/ToolChains.cpp
@@ -4860,7 +4860,7 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back("/usr/lib");
-  getFilePaths().push_back("/usr/lib/gcc50");
+  getFilePaths().push_back("@RAVEN_GCC@");
 }
 
 Tool *DragonFly::buildAssembler() const {
@@ -4871,6 +4871,8 @@ Tool *DragonFly::buildLinker() const {
   return new tools::dragonfly::Linker(*this);
 }
 
+bool DragonFly::HasNativeLLVMSupport() const { return true; }
+
 /// CUDA toolchain.  Our assembler is ptxas, and our "linker" is fatbinary,
 /// which isn't properly a linker but nonetheless performs the step of stitching
 /// together object files from the assembler into a single blob.
