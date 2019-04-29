--- ../zig-0.4.0.orig/std/os/file.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/os/file.zig	2019-04-26 15:40:41.549379000 +0300
@@ -237,7 +237,7 @@
 
     pub fn seekForward(self: File, amount: isize) SeekError!void {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 const result = posix.lseek(self.handle, amount, posix.SEEK_CUR);
                 const err = posix.getErrno(result);
                 if (err > 0) {
@@ -268,7 +268,7 @@
 
     pub fn seekTo(self: File, pos: usize) SeekError!void {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 const ipos = try math.cast(isize, pos);
                 const result = posix.lseek(self.handle, ipos, posix.SEEK_SET);
                 const err = posix.getErrno(result);
@@ -309,7 +309,7 @@
 
     pub fn getPos(self: File) GetSeekPosError!usize {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 const result = posix.lseek(self.handle, 0, posix.SEEK_CUR);
                 const err = posix.getErrno(result);
                 if (err > 0) {
