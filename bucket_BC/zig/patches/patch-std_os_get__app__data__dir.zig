--- std/os/get_app_data_dir.zig.orig	2019-04-08 19:41:41 UTC
+++ std/os/get_app_data_dir.zig
@@ -43,7 +43,7 @@ pub fn getAppDataDir(allocator: *mem.All
             };
             return os.path.join(allocator, [][]const u8{ home_dir, "Library", "Application Support", appname });
         },
-        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => {
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
             const home_dir = os.getEnvPosix("HOME") orelse {
                 // TODO look in /etc/passwd
                 return error.AppDataDirUnavailable;
