--- std/os/get_user_id.zig.orig	2019-04-08 19:41:41 UTC
+++ std/os/get_user_id.zig
@@ -11,7 +11,7 @@ pub const UserInfo = struct {
 /// POSIX function which gets a uid from username.
 pub fn getUserInfo(name: []const u8) !UserInfo {
     return switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => posixGetUserInfo(name),
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => posixGetUserInfo(name),
         else => @compileError("Unsupported OS"),
     };
 }
