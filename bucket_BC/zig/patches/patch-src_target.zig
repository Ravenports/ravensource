--- src/target.zig.orig	2024-06-06 19:05:11 UTC
+++ src/target.zig
@@ -291,7 +291,7 @@ pub fn libcFullLinkFlags(target: std.Tar
     // The linking order of these is significant and should match the order other
     // c compilers such as gcc or clang use.
     return switch (target.os.tag) {
-        .netbsd, .openbsd => &[_][]const u8{
+        .netbsd, .openbsd, .freebsd, .dragonfly => &[_][]const u8{
             "-lm",
             "-lpthread",
             "-lc",
