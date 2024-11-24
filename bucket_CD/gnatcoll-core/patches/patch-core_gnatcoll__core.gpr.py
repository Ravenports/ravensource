Do not use different implementations on linux.
At least the Blake3 versions use additional assembly files.
Let us keep everything uniform with the least amount of differences
between platforms.

--- core/gnatcoll_core.gpr.py.orig	2024-09-24 09:28:32 UTC
+++ core/gnatcoll_core.gpr.py
@@ -38,19 +38,13 @@ class GNATCollCore(BuilderApp):
 
     def adjust_config(self, gpr: GPRTool, args: argparse.Namespace) -> None:
         # Compute which implementation should be used for blake3
-        if gpr.target in ("x86_64-linux", "aarch64-linux", "x86_64-windows"):
-            blake3_arch = gpr.target
-        else:
-            blake3_arch = "generic"
+        blake3_arch = "generic"
 
         logging.debug(f"blake3 implementation: {blake3_arch}")
         gpr.set_variable("GNATCOLL_BLAKE3_ARCH", blake3_arch)
 
         # Compute which implementation should be used for xxhash
-        if gpr.target in ("x86_64-linux", "x86_64-windows"):
-            xxhash_arch = "x86_64"
-        else:
-            xxhash_arch = "generic"
+        xxhash_arch = "generic"
 
         logging.debug(f"xxhash implementation: {xxhash_arch}")
         gpr.set_variable("GNATCOLL_XXHASH_ARCH", xxhash_arch)
