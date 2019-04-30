--- build.zig.orig	2019-04-08 19:41:41 UTC
+++ build.zig
@@ -312,7 +312,7 @@ fn configureStage2(b: *Builder, exe: var
     }
     dependOnLib(b, exe, ctx.llvm);
 
-    if (exe.target.getOs() == builtin.Os.linux) {
+    if (exe.target.getOs() == builtin.Os.linux or exe.target.isDragonFly()) {
         try addCxxKnownPath(b, ctx, exe, "libstdc++.a",
             \\Unable to determine path to libstdc++.a
             \\On Fedora, install libstdc++-static and try again.
