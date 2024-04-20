--- build.zig.orig	2024-04-19 21:00:35 UTC
+++ build.zig
@@ -723,25 +723,14 @@ fn addCmakeCfgOptionsToExe(
             .windows => {
                 if (exe.rootModuleTarget().abi != .msvc) exe.linkLibCpp();
             },
-            .freebsd => {
-                if (static) {
-                    try addCxxKnownPath(b, cfg, exe, b.fmt("libc++.{s}", .{lib_suffix}), null, need_cpp_includes);
-                    try addCxxKnownPath(b, cfg, exe, b.fmt("libgcc_eh.{s}", .{lib_suffix}), null, need_cpp_includes);
-                } else {
-                    try addCxxKnownPath(b, cfg, exe, b.fmt("libc++.{s}", .{lib_suffix}), null, need_cpp_includes);
-                }
-            },
             .openbsd => {
                 try addCxxKnownPath(b, cfg, exe, b.fmt("libc++.{s}", .{lib_suffix}), null, need_cpp_includes);
                 try addCxxKnownPath(b, cfg, exe, b.fmt("libc++abi.{s}", .{lib_suffix}), null, need_cpp_includes);
             },
-            .netbsd, .dragonfly => {
-                if (static) {
-                    try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
-                    try addCxxKnownPath(b, cfg, exe, b.fmt("libgcc_eh.{s}", .{lib_suffix}), null, need_cpp_includes);
-                } else {
-                    try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
-                }
+            .netbsd, .dragonfly, .freebsd => {
+                exe.addObjectFile(.{ .cwd_relative = "@GCC_LIBDIR@/libstdc++.a" });
+                exe.addObjectFile(.{ .cwd_relative = "@GCC_TARGET_LIBDIR@/libgcc_eh.a" });
+                exe.addRPath(.{ .cwd_relative = "@LOCALBASE@/lib" });
             },
             .solaris, .illumos => {
                 try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
