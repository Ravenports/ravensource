--- src/link/Elf.zig.orig	2024-06-06 19:05:11 UTC
+++ src/link/Elf.zig
@@ -5281,19 +5281,22 @@ const CsuObjects = struct {
             const crt_dir_path = lci.crt_dir orelse return error.LibCInstallationMissingCRTDir;
             switch (target.os.tag) {
                 .dragonfly => {
+                    const gcc_dir_path = "@GCC_TARGET_LIBDIR@";
                     if (result.crt0) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
                     if (result.crti) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
                     if (result.crtn) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
 
-                    var gccv: []const u8 = undefined;
-                    if (target.os.version_range.semver.isAtLeast(.{ .major = 5, .minor = 4, .patch = 0 }) orelse true) {
-                        gccv = "gcc80";
-                    } else {
-                        gccv = "gcc54";
-                    }
+                    if (result.crtbegin) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ gcc_dir_path, obj.* });
+                    if (result.crtend) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ gcc_dir_path, obj.* });
+                },
+                .freebsd => {
+                    const gcc_dir_path = "@GCC_TARGET_LIBDIR@";
+                    if (result.crt0) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
+                    if (result.crti) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
+                    if (result.crtn) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
 
-                    if (result.crtbegin) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, gccv, obj.* });
-                    if (result.crtend) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, gccv, obj.* });
+                    if (result.crtbegin) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ gcc_dir_path, obj.* });
+                    if (result.crtend) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ gcc_dir_path, obj.* });
                 },
                 .haiku => {
                     const gcc_dir_path = lci.gcc_dir orelse return error.LibCInstallationMissingCRTDir;
