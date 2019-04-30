--- std/c.zig.orig	2019-04-08 19:41:41 UTC
+++ std/c.zig
@@ -7,6 +7,7 @@ pub use switch (builtin.os) {
     Os.macosx, Os.ios => @import("c/darwin.zig"),
     Os.freebsd => @import("c/freebsd.zig"),
     Os.netbsd => @import("c/netbsd.zig"),
+    Os.dragonfly => @import("c/dragonfly.zig"),
     else => struct {},
 };
 
