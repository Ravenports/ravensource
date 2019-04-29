--- ../zig-0.4.0.orig/std/os/time.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/os/time.zig	2019-04-26 15:51:05.802505000 +0300
@@ -14,7 +14,7 @@
 /// Sleep for the specified duration
 pub fn sleep(nanoseconds: u64) void {
     switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd, Os.dragonfly => {
             const s = nanoseconds / ns_per_s;
             const ns = nanoseconds % ns_per_s;
             posixSleep(@intCast(u63, s), @intCast(u63, ns));
@@ -62,7 +62,7 @@
 /// Get the posix timestamp, UTC, in milliseconds
 pub const milliTimestamp = switch (builtin.os) {
     Os.windows => milliTimestampWindows,
-    Os.linux, Os.freebsd, Os.netbsd => milliTimestampPosix,
+    Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => milliTimestampPosix,
     Os.macosx, Os.ios => milliTimestampDarwin,
     else => @compileError("Unsupported OS"),
 };
@@ -178,7 +178,7 @@
                 debug.assert(err != windows.FALSE);
                 self.start_time = @intCast(u64, start_time);
             },
-            Os.linux, Os.freebsd, Os.netbsd => {
+            Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => {
                 //On Linux, seccomp can do arbitrary things to our ability to call
                 //  syscalls, including return any errno value it wants and
                 //  inconsistently throwing errors. Since we can't account for
@@ -214,7 +214,7 @@
         var clock = clockNative() - self.start_time;
         return switch (builtin.os) {
             Os.windows => @divFloor(clock * ns_per_s, self.frequency),
-            Os.linux, Os.freebsd, Os.netbsd => clock,
+            Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => clock,
             Os.macosx, Os.ios => @divFloor(clock * self.frequency.numer, self.frequency.denom),
             else => @compileError("Unsupported OS"),
         };
@@ -235,7 +235,7 @@
 
     const clockNative = switch (builtin.os) {
         Os.windows => clockWindows,
-        Os.linux, Os.freebsd, Os.netbsd => clockLinux,
+        Os.linux, Os.freebsd, Os.netbsd, Os.dragonfly => clockLinux,
         Os.macosx, Os.ios => clockDarwin,
         else => @compileError("Unsupported OS"),
     };
