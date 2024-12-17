--- tools/gyp/pylib/gyp/xcode_emulation.py.orig	2024-11-20 14:52:49 UTC
+++ tools/gyp/pylib/gyp/xcode_emulation.py
@@ -608,7 +608,7 @@ class XcodeSettings:
 
         self._Appendf(cflags, "GCC_OPTIMIZATION_LEVEL", "-O%s", default="s")
 
-        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES"):
+        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO"):
             dbg_format = self._Settings().get("DEBUG_INFORMATION_FORMAT", "dwarf")
             if dbg_format == "dwarf":
                 cflags.append("-gdwarf-2")
@@ -1101,7 +1101,7 @@ class XcodeSettings:
         # For static libraries, no dSYMs are created.
         result = []
         if (
-            self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES")
+            self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO")
             and self._Test(
                 "DEBUG_INFORMATION_FORMAT", "dwarf-with-dsym", default="dwarf"
             )
