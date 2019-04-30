--- std/build.zig.orig	2019-04-08 19:41:41 UTC
+++ std/build.zig
@@ -894,6 +894,13 @@ pub const Target = union(enum) {
         };
     }
 
+    pub fn isDragonFly(self: *const Target) bool {
+        return switch (self.getOs()) {
+            builtin.Os.dragonfly => true,
+            else => false,
+        };
+    }
+
     pub fn wantSharedLibSymLinks(self: *const Target) bool {
         return !self.isWindows();
     }
