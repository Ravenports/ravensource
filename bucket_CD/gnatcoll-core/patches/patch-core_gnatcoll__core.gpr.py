--- core/gnatcoll_core.gpr.py.orig	2025-11-28 12:36:47 UTC
+++ core/gnatcoll_core.gpr.py
@@ -38,7 +38,7 @@ class GNATCollCore(BuilderApp):
 
     def adjust_config(self, gpr: GPRTool, args: argparse.Namespace) -> None:
         # Compute which implementation should be used for blake3
-        if gpr.target in ("x86_64-linux", "aarch64-linux", "x86_64-windows"):
+        if gpr.target.startswith(("x86_64-", "aarch64-")):
             blake3_arch = gpr.target
         else:
             blake3_arch = "generic"
@@ -47,7 +47,7 @@ class GNATCollCore(BuilderApp):
         gpr.set_variable("GNATCOLL_BLAKE3_ARCH", blake3_arch)
 
         # Compute which implementation should be used for xxhash
-        if gpr.target in ("x86_64-linux", "x86_64-windows"):
+        if gpr.target.startswith("x86_64-"):
             xxhash_arch = "x86_64"
         else:
             xxhash_arch = "generic"
