--- ../zig-0.4.0.orig/std/c.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/c.zig	2019-04-26 15:36:35.708121000 +0300
@@ -7,6 +7,7 @@
     Os.macosx, Os.ios => @import("c/darwin.zig"),
     Os.freebsd => @import("c/freebsd.zig"),
     Os.netbsd => @import("c/netbsd.zig"),
+    Os.dragonfly => @import("c/dragonfly.zig"),
     else => struct {},
 };
 
