--- source/spawn/spawn-posix.ads.orig	2025-01-28 16:38:20 UTC
+++ source/spawn/spawn-posix.ads
@@ -156,7 +156,7 @@ package Spawn.Posix is
      (fd     : Interfaces.C.int;
       buf    : out Interfaces.C.char_array;
       buflen : Interfaces.C.size_t) return Interfaces.C.int
-     with Import, Convention => C, External_Name => "ptsname_r";
+     with Import, Convention => C, External_Name => "__ptsname_r";
 
    function setsid return Interfaces.C.int
      with Import, Convention => C, External_Name => "setsid";
