--- build.zig.orig	2023-01-17 23:40:56 UTC
+++ build.zig
@@ -609,19 +609,11 @@ fn addCmakeCfgOptionsToExe(
             .ios, .macos, .watchos, .tvos => {
                 exe.linkSystemLibrary("c++");
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
+            .netbsd, .dragonfly, .freebsd => {
                 if (static) {
                     try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
                     try addCxxKnownPath(b, cfg, exe, b.fmt("libgcc_eh.{s}", .{lib_suffix}), null, need_cpp_includes);
