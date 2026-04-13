--- lib/Driver/ToolChains/Solaris.cpp.orig	2025-12-12 10:35:47 UTC
+++ lib/Driver/ToolChains/Solaris.cpp
@@ -109,12 +109,17 @@ void solaris::Linker::ConstructJob(Compi
     }
   }
 
+  CmdArgs.push_back("-L@RAVEN_GCC@");
+  CmdArgs.push_back("-L@LOCALBASE@/lib");
+
   if (Args.hasArg(options::OPT_static)) {
     CmdArgs.push_back("-Bstatic");
     CmdArgs.push_back("-dn");
   } else {
     if (!Args.hasArg(options::OPT_r) && Args.hasArg(options::OPT_shared))
       CmdArgs.push_back("-shared");
+      CmdArgs.push_back("-R@RAVEN_GCC@");
+      CmdArgs.push_back("-R@LOCALBASE@/lib");
 
     // libpthread has been folded into libc since Solaris 10, no need to do
     // anything for pthreads. Claim argument to avoid warning.
@@ -405,21 +410,7 @@ void Solaris::AddClangSystemIncludeArgs(
 void Solaris::addLibStdCxxIncludePaths(
     const llvm::opt::ArgList &DriverArgs,
     llvm::opt::ArgStringList &CC1Args) const {
-  // We need a detected GCC installation on Solaris (similar to Linux)
-  // to provide libstdc++'s headers.
-  if (!GCCInstallation.isValid())
-    return;
-
-  // By default, look for the C++ headers in an include directory adjacent to
-  // the lib directory of the GCC installation.
-  // On Solaris this usually looks like /usr/gcc/X.Y/include/c++/X.Y.Z
-  StringRef LibDir = GCCInstallation.getParentLibPath();
-  StringRef TripleStr = GCCInstallation.getTriple().str();
-  const Multilib &Multilib = GCCInstallation.getMultilib();
-  const GCCVersion &Version = GCCInstallation.getVersion();
-
-  // The primary search for libstdc++ supports multiarch variants.
-  addLibStdCXXIncludePaths(LibDir.str() + "/../include/c++/" + Version.Text,
-                           TripleStr, Multilib.includeSuffix(), DriverArgs,
-                           CC1Args);
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/@RAVEN_TRIPLE@");
 }
