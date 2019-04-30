--- ../zig-0.4.0.orig/std/os/path.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/os/path.zig	2019-04-26 15:42:19.949871000 +0300
@@ -1226,7 +1226,7 @@
             const pathname_w = try windows_util.cStrToPrefixedFileW(pathname);
             return realW(out_buffer, pathname_w);
         },
-        Os.freebsd, Os.netbsd, Os.macosx, Os.ios => {
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             // TODO instead of calling the libc function here, port the implementation to Zig
             const err = posix.getErrno(posix.realpath(pathname, out_buffer));
             switch (err) {
@@ -1267,7 +1267,7 @@
             const pathname_w = try windows_util.sliceToPrefixedFileW(pathname);
             return realW(out_buffer, &pathname_w);
         },
-        Os.macosx, Os.ios, Os.linux, Os.freebsd, Os.netbsd => {
+        Os.macosx, Os.ios, Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => {
             const pathname_c = try os.toPosixPath(pathname);
             return realC(out_buffer, &pathname_c);
         },
