--- src/link/Elf.zig.orig	2023-01-17 23:40:56 UTC
+++ src/link/Elf.zig
@@ -3191,19 +3191,22 @@ const CsuObjects = struct {
             const crt_dir_path = lci.crt_dir orelse return error.LibCInstallationMissingCRTDir;
             switch (link_options.target.os.tag) {
                 .dragonfly => {
+                    const gcc_dir_path = "@GCC_TARGET_LIBDIR@";
                     if (result.crt0) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
                     if (result.crti) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
                     if (result.crtn) |*obj| obj.* = try fs.path.join(arena, &[_][]const u8{ crt_dir_path, obj.* });
 
-                    var gccv: []const u8 = undefined;
-                    if (link_options.target.os.version_range.semver.isAtLeast(.{ .major = 5, .minor = 4 }) orelse true) {
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
