--- lib/std/zig/LibCInstallation.zig.orig	2025-05-22 05:46:47 UTC
+++ lib/std/zig/LibCInstallation.zig
@@ -973,23 +973,29 @@ pub fn resolveCrtPaths(
     };
     switch (target.os.tag) {
         .dragonfly => {
-            const gccv: []const u8 = if (target.os.version_range.semver.isAtLeast(.{
-                .major = 5,
-                .minor = 4,
-                .patch = 0,
-            }) orelse true) "gcc80" else "gcc54";
+            const gcc_dir_path: Path = .{
+                .root_dir = std.Build.Cache.Directory.cwd(),
+                .sub_path = "@GCC_TARGET_LIBDIR@",
+            };
+            return .{
+                .crt0 = if (crt_basenames.crt0) |basename| try crt_dir_path.join(arena, basename) else null,
+                .crti = if (crt_basenames.crti) |basename| try crt_dir_path.join(arena, basename) else null,
+                .crtn = if (crt_basenames.crtn) |basename| try crt_dir_path.join(arena, basename) else null,
+                .crtbegin = if (crt_basenames.crtbegin) |basename| try gcc_dir_path.join(arena, basename) else null,
+                .crtend = if (crt_basenames.crtend) |basename| try gcc_dir_path.join(arena, basename) else null,
+            };
+        },
+        .freebsd => {
+            const gcc_dir_path: Path = .{
+                .root_dir = std.Build.Cache.Directory.cwd(),
+                .sub_path = "@GCC_TARGET_LIBDIR@",
+            };
             return .{
                 .crt0 = if (crt_basenames.crt0) |basename| try crt_dir_path.join(arena, basename) else null,
                 .crti = if (crt_basenames.crti) |basename| try crt_dir_path.join(arena, basename) else null,
-                .crtbegin = if (crt_basenames.crtbegin) |basename| .{
-                    .root_dir = crt_dir_path.root_dir,
-                    .sub_path = try fs.path.join(arena, &.{ crt_dir_path.sub_path, gccv, basename }),
-                } else null,
-                .crtend = if (crt_basenames.crtend) |basename| .{
-                    .root_dir = crt_dir_path.root_dir,
-                    .sub_path = try fs.path.join(arena, &.{ crt_dir_path.sub_path, gccv, basename }),
-                } else null,
                 .crtn = if (crt_basenames.crtn) |basename| try crt_dir_path.join(arena, basename) else null,
+                .crtbegin = if (crt_basenames.crtbegin) |basename| try gcc_dir_path.join(arena, basename) else null,
+                .crtend = if (crt_basenames.crtend) |basename| try gcc_dir_path.join(arena, basename) else null,
             };
         },
         .haiku => {
