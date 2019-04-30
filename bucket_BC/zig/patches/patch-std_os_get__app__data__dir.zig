--- ../zig-0.4.0.orig/std/os/get_app_data_dir.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/os/get_app_data_dir.zig	2019-04-26 15:47:37.821462000 +0300
@@ -43,7 +43,7 @@
             };
             return os.path.join(allocator, [][]const u8{ home_dir, "Library", "Application Support", appname });
         },
-        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => {
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => {
             const home_dir = os.getEnvPosix("HOME") orelse {
                 // TODO look in /etc/passwd
                 return error.AppDataDirUnavailable;
