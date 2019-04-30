--- std/event/net.zig.orig	2019-04-08 19:41:41 UTC
+++ std/event/net.zig
@@ -202,7 +202,7 @@ pub async fn writevPosix(loop: *Loop, fd
 pub async fn readvPosix(loop: *std.event.Loop, fd: i32, iov: [*]posix.iovec, count: usize) !usize {
     while (true) {
         switch (builtin.os) {
-            builtin.Os.linux, builtin.Os.freebsd, builtin.Os.macosx => {
+            builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.dragonfly => {
                 const rc = posix.readv(fd, iov, count);
                 const err = posix.getErrno(rc);
                 switch (err) {
