--- tools/clang/lib/Driver/ToolChains/Linux.cpp.orig	2017-06-03 16:47:06 UTC
+++ tools/clang/lib/Driver/ToolChains/Linux.cpp
@@ -210,10 +210,6 @@ Linux::Linux(const Driver &D, const llvm
 
   Distro Distro(D.getVFS());
 
-  if (Distro.IsOpenSUSE() || Distro.IsUbuntu()) {
-    ExtraOpts.push_back("-z");
-    ExtraOpts.push_back("relro");
-  }
 
   if (Arch == llvm::Triple::arm || Arch == llvm::Triple::thumb)
     ExtraOpts.push_back("-X");
@@ -232,13 +228,7 @@ Linux::Linux(const Driver &D, const llvm
   // Android loader does not support .gnu.hash.
   // Hexagon linker/loader does not support .gnu.hash
   if (!IsMips && !IsAndroid && !IsHexagon) {
-    if (Distro.IsRedhat() || Distro.IsOpenSUSE() ||
-        (Distro.IsUbuntu() && Distro >= Distro::UbuntuMaverick))
       ExtraOpts.push_back("--hash-style=gnu");
-
-    if (Distro.IsDebian() || Distro.IsOpenSUSE() || Distro == Distro::UbuntuLucid ||
-        Distro == Distro::UbuntuJaunty || Distro == Distro::UbuntuKarmic)
-      ExtraOpts.push_back("--hash-style=both");
   }
 
   if (Distro.IsRedhat() && Distro != Distro::RHEL5 && Distro != Distro::RHEL6)
@@ -248,7 +238,6 @@ Linux::Linux(const Driver &D, const llvm
   ExtraOpts.push_back("--build-id");
 #endif
 
-  if (Distro.IsOpenSUSE())
     ExtraOpts.push_back("--enable-new-dtags");
 
   // The selection of paths to try here is designed to match the patterns which
@@ -328,6 +317,8 @@ Linux::Linux(const Driver &D, const llvm
   addPathIfExists(D, SysRoot + "/lib/../" + OSLibDir, Paths);
   addPathIfExists(D, SysRoot + "/usr/lib/" + MultiarchTriple, Paths);
   addPathIfExists(D, SysRoot + "/usr/lib/../" + OSLibDir, Paths);
+  addPathIfExists(D, SysRoot + "@RAVEN_GCC@", Paths);
+  addPathIfExists(D, SysRoot + "@RAVEN_GCC_TARGET@", Paths);
 
   // Try walking via the GCC triple path in case of biarch or multiarch GCC
   // installations with strange symlinks.
@@ -764,10 +755,9 @@ void Linux::addLibStdCxxIncludePaths(con
   const GCCVersion &Version = GCCInstallation.getVersion();
 
   // The primary search for libstdc++ supports multiarch variants.
-  if (addLibStdCXXIncludePaths(LibDir.str() + "/../include",
-                               "/c++/" + Version.Text, TripleStr,
-                               GCCMultiarchTriple, TargetMultiarchTriple,
-                               Multilib.includeSuffix(), DriverArgs, CC1Args))
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@/backward");
+  addSystemInclude(DriverArgs, CC1Args, "@RAVEN_GXX_HEADERS_DIR@" + TripleStr);
     return;
 
   // Otherwise, fall back on a bunch of options which don't use multiarch
