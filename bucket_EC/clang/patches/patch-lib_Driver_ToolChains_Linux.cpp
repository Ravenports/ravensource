--- lib/Driver/ToolChains/Linux.cpp.orig	2026-03-23 18:46:22 UTC
+++ lib/Driver/ToolChains/Linux.cpp
@@ -803,36 +803,7 @@ void Linux::AddClangSystemIncludeArgs(co
 
 void Linux::addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                      llvm::opt::ArgStringList &CC1Args) const {
-  // We need a detected GCC installation on Linux to provide libstdc++'s
-  // headers in odd Linuxish places.
-  if (!GCCInstallation.isValid())
-    return;
-
-  // Try generic GCC detection first.
-  if (Generic_GCC::addGCCLibStdCxxIncludePaths(DriverArgs, CC1Args))
-    return;
-
-  StringRef LibDir = GCCInstallation.getParentLibPath();
-  const Multilib &Multilib = GCCInstallation.getMultilib();
-  const GCCVersion &Version = GCCInstallation.getVersion();
-
-  StringRef TripleStr = GCCInstallation.getTriple().str();
-  const std::string LibStdCXXIncludePathCandidates[] = {
-      // Android standalone toolchain has C++ headers in yet another place.
-      LibDir.str() + "/../" + TripleStr.str() + "/include/c++/" + Version.Text,
-      // Freescale SDK C++ headers are directly in <sysroot>/usr/include/c++,
-      // without a subdirectory corresponding to the gcc version.
-      LibDir.str() + "/../include/c++",
-      // Cray's gcc installation puts headers under "g++" without a
-      // version suffix.
-      LibDir.str() + "/../include/g++",
-  };
-
-  for (const auto &IncludePath : LibStdCXXIncludePathCandidates) {
-    if (addLibStdCXXIncludePaths(IncludePath, TripleStr,
-                                 Multilib.includeSuffix(), DriverArgs, CC1Args))
-      break;
-  }
+  Generic_GCC::addLibStdCxxIncludePaths(DriverArgs, CC1Args);
 }
 
 void Linux::AddCudaIncludeArgs(const ArgList &DriverArgs,
