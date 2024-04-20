--- lib/Driver/ToolChains/DragonFly.h.orig	2024-04-17 00:21:15 UTC
+++ lib/Driver/ToolChains/DragonFly.h
@@ -53,6 +53,7 @@ class LLVM_LIBRARY_VISIBILITY DragonFly
 public:
   DragonFly(const Driver &D, const llvm::Triple &Triple,
             const llvm::opt::ArgList &Args);
+  bool HasNativeLLVMSupport() const override;
 
   bool IsMathErrnoDefault() const override { return false; }
 
