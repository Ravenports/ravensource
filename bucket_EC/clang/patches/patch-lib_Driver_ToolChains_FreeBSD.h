--- lib/Driver/ToolChains/FreeBSD.h.orig	2026-11-02 10:45:15 UTC
+++ lib/Driver/ToolChains/FreeBSD.h
@@ -66,11 +66,11 @@ public:
     return ToolChain::RLT_CompilerRT;
   }
   CXXStdlibType GetDefaultCXXStdlibType() const override {
-    return ToolChain::CST_Libcxx;
+    return ToolChain::CST_Libstdcxx;
   }
 
-  void AddCXXStdlibLibArgs(const llvm::opt::ArgList &Args,
-                           llvm::opt::ArgStringList &CmdArgs) const override;
+  void addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
+                                llvm::opt::ArgStringList &CC1Args) const override;
   void AddCudaIncludeArgs(const llvm::opt::ArgList &DriverArgs,
                           llvm::opt::ArgStringList &CC1Args) const override;
   void AddHIPIncludeArgs(const llvm::opt::ArgList &DriverArgs,
