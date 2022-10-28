--- lib/Driver/ToolChains/DragonFly.h.orig	2022-10-18 06:29:45 UTC
+++ lib/Driver/ToolChains/DragonFly.h
@@ -52,6 +52,7 @@ class LLVM_LIBRARY_VISIBILITY DragonFly
 public:
   DragonFly(const Driver &D, const llvm::Triple &Triple,
             const llvm::opt::ArgList &Args);
+  bool HasNativeLLVMSupport() const override;
 
   bool IsMathErrnoDefault() const override { return false; }
 
