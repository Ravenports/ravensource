--- /home/tse/Packages/zig-0.4.0.orig/std/debug.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/debug.zig	2019-04-26 15:25:13.775940000 +0300
@@ -290,7 +290,7 @@
 pub fn printSourceAtAddress(debug_info: *DebugInfo, out_stream: var, address: usize, tty_color: bool) !void {
     switch (builtin.os) {
         builtin.Os.macosx => return printSourceAtAddressMacOs(debug_info, out_stream, address, tty_color),
-        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => return printSourceAtAddressLinux(debug_info, out_stream, address, tty_color),
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => return printSourceAtAddressLinux(debug_info, out_stream, address, tty_color),
         builtin.Os.windows => return printSourceAtAddressWindows(debug_info, out_stream, address, tty_color),
         else => return error.UnsupportedOperatingSystem,
     }
@@ -775,7 +775,7 @@
 
 pub fn openSelfDebugInfo(allocator: *mem.Allocator) !DebugInfo {
     switch (builtin.os) {
-        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => return openSelfDebugInfoLinux(allocator),
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => return openSelfDebugInfoLinux(allocator),
         builtin.Os.macosx, builtin.Os.ios => return openSelfDebugInfoMacOs(allocator),
         builtin.Os.windows => return openSelfDebugInfoWindows(allocator),
         else => return error.UnsupportedOperatingSystem,
@@ -1200,7 +1200,7 @@
         sect_contribs: []pdb.SectionContribEntry,
         modules: []Module,
     },
-    builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => DwarfInfo,
+    builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd, builtin.Os.dragonfly => DwarfInfo,
     else => @compileError("Unsupported OS"),
 };
 
