--- ../zig-0.4.0.orig/build.zig	2019-04-09 01:30:42.000000000 +0300
+++ build.zig	2019-04-29 23:05:09.457538000 +0300
@@ -310,11 +310,11 @@
         addCppLib(b, exe, ctx.cmake_binary_dir, "embedded_lld_coff");
         addCppLib(b, exe, ctx.cmake_binary_dir, "embedded_lld_lib");
     }
     dependOnLib(b, exe, ctx.llvm);
 
-    if (exe.target.getOs() == builtin.Os.linux) {
+    if (exe.target.getOs() == builtin.Os.linux or exe.target.isDragonFly()) {
         try addCxxKnownPath(b, ctx, exe, "libstdc++.a",
             \\Unable to determine path to libstdc++.a
             \\On Fedora, install libstdc++-static and try again.
         );
 
