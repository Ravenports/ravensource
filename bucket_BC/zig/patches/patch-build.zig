--- build.zig.orig	2026-10-01 22:02:33 UTC
+++ build.zig
@@ -1001,6 +1001,7 @@ fn addCmakeCfgOptionsToExe(
                     else => |e| return e,
                 };
                 mod.linkSystemLibrary("unwind", .{});
+                exe.root_module.addRPathSpecial("@GCC_LIBDIR@");
             },
             .driverkit, .ios, .maccatalyst, .macos, .tvos, .visionos, .watchos => {
                 mod.link_libcpp = true;
@@ -1008,20 +1009,10 @@ fn addCmakeCfgOptionsToExe(
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
+                exe.root_module.addObjectFile(.{ .cwd_relative = "@GCC_LIBDIR@/libstdc++.a" });
+                exe.root_module.addObjectFile(.{ .cwd_relative = "@GCC_TARGET_LIBDIR@/libgcc_eh.a" });
+                exe.root_module.addRPathSpecial("@LOCALBASE@/lib");
             },
             .illumos => {
                 try addCxxKnownPath(b, cfg, exe, b.fmt("libstdc++.{s}", .{lib_suffix}), null, need_cpp_includes);
