--- tools/clang/lib/Driver/ToolChains.h.orig	2017-01-05 16:52:29 UTC
+++ tools/clang/lib/Driver/ToolChains.h
@@ -854,6 +854,8 @@ public:
   DragonFly(const Driver &D, const llvm::Triple &Triple,
             const llvm::opt::ArgList &Args);
 
+  bool HasNativeLLVMSupport() const override;
+
   bool IsMathErrnoDefault() const override { return false; }
 
 protected:
