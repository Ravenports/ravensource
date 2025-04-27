--- lib/Driver/ToolChains/FreeBSD.h.orig	2024-10-29 10:09:39 UTC
+++ lib/Driver/ToolChains/FreeBSD.h
@@ -66,13 +66,13 @@ public:
     return ToolChain::RLT_CompilerRT;
   }
   CXXStdlibType GetDefaultCXXStdlibType() const override {
-    return ToolChain::CST_Libcxx;
+    return ToolChain::CST_Libstdcxx;
   }
 
+  void addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
+                             llvm::opt::ArgStringList &CC1Args) const override;
   void addLibCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                              llvm::opt::ArgStringList &CC1Args) const override;
-  void AddCXXStdlibLibArgs(const llvm::opt::ArgList &Args,
-                           llvm::opt::ArgStringList &CmdArgs) const override;
   void AddCudaIncludeArgs(const llvm::opt::ArgList &DriverArgs,
                           llvm::opt::ArgStringList &CC1Args) const override;
   void AddHIPIncludeArgs(const llvm::opt::ArgList &DriverArgs,
