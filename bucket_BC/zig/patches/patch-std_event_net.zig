--- ../zig-0.4.0.orig/std/event/net.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/event/net.zig	2019-04-26 15:57:32.304444000 +0300
@@ -202,7 +202,7 @@
 pub async fn readvPosix(loop: *std.event.Loop, fd: i32, iov: [*]posix.iovec, count: usize) !usize {
     while (true) {
         switch (builtin.os) {
-            builtin.Os.linux, builtin.Os.freebsd, builtin.Os.macosx => {
+            builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.dragonfly => {
                 const rc = posix.readv(fd, iov, count);
                 const err = posix.getErrno(rc);
                 switch (err) {
