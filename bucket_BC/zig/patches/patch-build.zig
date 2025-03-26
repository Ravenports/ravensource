--- build.zig.orig	2025-03-04 22:31:02 UTC
+++ build.zig
@@ -783,6 +783,7 @@ fn addCmakeCfgOptionsToExe(
                     else => |e| return e,
                 };
                 mod.linkSystemLibrary("unwind", .{});
+                exe.addRPath(.{ .cwd_relative = "@GCC_LIBDIR@" });
             },
             .ios, .macos, .watchos, .tvos, .visionos => {
                 mod.link_libcpp = true;
@@ -790,20 +791,10 @@ fn addCmakeCfgOptionsToExe(
             .windows => {
                 if (target.abi != .msvc) mod.link_libcpp = true;
             },
-            .freebsd => {
-                try addCxxKnownPath(b, cfg, exe, b.fmt("libc++.{s}", .{lib_suffix}), null, need_cpp_includes);
-                if (static) try addCxxKnownPath(b, cfg, exe, b.fmt("libgcc_eh.{s}", .{lib_suffix}), null, need_cpp_includes);
-            },
-            .openbsd => {
-                // - llvm requires libexecinfo which has conflicting symbols with libc++abi
-                // - only an issue with .a linking
-                // - workaround is to link c++abi dynamically
-                try addCxxKnownPath(b, cfg, exe, b.fmt("libc++.{s}", .{target.dynamicLibSuffix()[1..]}), null, need_cpp_includes);
-                try addCxxKnownPath(b, cfg, exe, b.fmt("libc++abi.{s}", .{target.dynamicLibSuffix()[1..]}), null, need_cpp_includes);
-            },
-            .netbsd, .dragonfly => {
-                try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
-                if (static) try addCxxKnownPath(b, cfg, exe, b.fmt("libgcc_eh.{s}", .{lib_suffix}), null, need_cpp_includes);
+            .netbsd, .dragonfly, .freebsd => {
+                exe.addObjectFile(.{ .cwd_relative = "@GCC_LIBDIR@/libstdc++.a" });
+                exe.addObjectFile(.{ .cwd_relative = "@GCC_TARGET_LIBDIR@/libgcc_eh.a" });
+                exe.addRPath(.{ .cwd_relative = "@LOCALBASE@/lib" });
             },
             .solaris, .illumos => {
                 try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
