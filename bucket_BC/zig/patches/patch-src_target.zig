--- src/target.zig.orig	2023-01-17 23:40:56 UTC
+++ src/target.zig
@@ -448,7 +448,7 @@ pub fn libcFullLinkFlags(target: std.Tar
     // The linking order of these is significant and should match the order other
     // c compilers such as gcc or clang use.
     return switch (target.os.tag) {
-        .netbsd, .openbsd => &[_][]const u8{
+        .netbsd, .openbsd, .freebsd, .dragonfly => &[_][]const u8{
             "-lm",
             "-lpthread",
             "-lc",
