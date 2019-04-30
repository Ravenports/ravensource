--- ../zig-0.4.0.orig/std/os/get_user_id.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/os/get_user_id.zig	2019-04-26 15:47:57.541562000 +0300
@@ -11,7 +11,7 @@
 /// POSIX function which gets a uid from username.
 pub fn getUserInfo(name: []const u8) !UserInfo {
     return switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => posixGetUserInfo(name),
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => posixGetUserInfo(name),
         else => @compileError("Unsupported OS"),
     };
 }
