--- tools/gyp/pylib/gyp/xcode_emulation.py.orig	2025-11-16 23:17:53 UTC
+++ tools/gyp/pylib/gyp/xcode_emulation.py
@@ -605,7 +605,7 @@ class XcodeSettings:
 
         self._Appendf(cflags, "GCC_OPTIMIZATION_LEVEL", "-O%s", default="s")
 
-        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES"):
+        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO"):
             dbg_format = self._Settings().get("DEBUG_INFORMATION_FORMAT", "dwarf")
             if dbg_format == "dwarf":
                 cflags.append("-gdwarf-2")
@@ -1097,7 +1097,7 @@ class XcodeSettings:
         # For static libraries, no dSYMs are created.
         result = []
         if (
-            self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES")
+            self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO")
             and self._Test(
                 "DEBUG_INFORMATION_FORMAT", "dwarf-with-dsym", default="dwarf"
             )
