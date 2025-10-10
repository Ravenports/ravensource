Do not generate debugging symbols (uses lots of disk space).

--- node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py.orig	1985-10-26 08:15:00 UTC
+++ node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py
@@ -605,7 +605,7 @@ class XcodeSettings:
 
         self._Appendf(cflags, "GCC_OPTIMIZATION_LEVEL", "-O%s", default="s")
 
-        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES"):
+        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO"):
             dbg_format = self._Settings().get("DEBUG_INFORMATION_FORMAT", "dwarf")
             if dbg_format == "dwarf":
                 cflags.append("-gdwarf-2")
