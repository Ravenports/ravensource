--- lib/Driver/ToolChains/DragonFly.h.orig	2025-04-16 00:23:49 UTC
+++ lib/Driver/ToolChains/DragonFly.h
@@ -53,6 +53,7 @@ class LLVM_LIBRARY_VISIBILITY DragonFly
 public:
   DragonFly(const Driver &D, const llvm::Triple &Triple,
             const llvm::opt::ArgList &Args);
+  bool HasNativeLLVMSupport() const override;
 
   bool IsMathErrnoDefault() const override { return false; }
 
@@ -63,6 +64,10 @@ public:
       const llvm::opt::ArgList &DriverArgs,
       llvm::opt::ArgStringList &CC1Args) const override;
 
+  CXXStdlibType GetDefaultCXXStdlibType() const override {
+    return ToolChain::CST_Libstdcxx;
+  }
+
 protected:
   Tool *buildAssembler() const override;
   Tool *buildLinker() const override;
