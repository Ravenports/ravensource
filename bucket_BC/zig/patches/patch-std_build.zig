--- ../zig-0.4.0.orig/std/build.zig	2019-04-08 22:41:41.000000000 +0300
+++ std/build.zig	2019-04-26 17:03:40.584496000 +0300
@@ -894,6 +894,13 @@
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
