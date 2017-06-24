--- tools/clang/lib/Driver/ToolChains.cpp.orig	2017-06-23 13:14:28 UTC
+++ tools/clang/lib/Driver/ToolChains.cpp
@@ -4112,10 +4112,6 @@ Linux::Linux(const Driver &D, const llvm
 
   Distro Distro(D.getVFS());
 
-  if (Distro.IsOpenSUSE() || Distro.IsUbuntu()) {
-    ExtraOpts.push_back("-z");
-    ExtraOpts.push_back("relro");
-  }
 
   if (Arch == llvm::Triple::arm || Arch == llvm::Triple::thumb)
     ExtraOpts.push_back("-X");
@@ -4132,13 +4128,7 @@ Linux::Linux(const Driver &D, const llvm
   // ABI requires a mapping between the GOT and the symbol table.
   // Android loader does not support .gnu.hash.
   if (!IsMips && !IsAndroid) {
-    if (Distro.IsRedhat() || Distro.IsOpenSUSE() ||
-        (Distro.IsUbuntu() && Distro >= Distro::UbuntuMaverick))
       ExtraOpts.push_back("--hash-style=gnu");
-
-    if (Distro.IsDebian() || Distro.IsOpenSUSE() || Distro == Distro::UbuntuLucid ||
-        Distro == Distro::UbuntuJaunty || Distro == Distro::UbuntuKarmic)
-      ExtraOpts.push_back("--hash-style=both");
   }
 
   if (Distro.IsRedhat() && Distro != Distro::RHEL5 && Distro != Distro::RHEL6)
@@ -4148,7 +4138,6 @@ Linux::Linux(const Driver &D, const llvm
   ExtraOpts.push_back("--build-id");
 #endif
 
-  if (Distro.IsOpenSUSE())
     ExtraOpts.push_back("--enable-new-dtags");
 
   // The selection of paths to try here is designed to match the patterns which
@@ -4228,6 +4217,8 @@ Linux::Linux(const Driver &D, const llvm
   addPathIfExists(D, SysRoot + "/lib/../" + OSLibDir, Paths);
   addPathIfExists(D, SysRoot + "/usr/lib/" + MultiarchTriple, Paths);
   addPathIfExists(D, SysRoot + "/usr/lib/../" + OSLibDir, Paths);
+  addPathIfExists(D, SysRoot + "@RAVEN_GCC@", Paths);
+  addPathIfExists(D, SysRoot + "@RAVEN_GCC_TARGET@", Paths);
 
   // Try walking via the GCC triple path in case of biarch or multiarch GCC
   // installations with strange symlinks.
@@ -4664,10 +4655,9 @@ void Linux::addLibStdCxxIncludePaths(con
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
