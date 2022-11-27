--- source/spawn/spawn-posix.ads.orig	2022-09-26 13:44:48 UTC
+++ source/spawn/spawn-posix.ads
@@ -154,7 +154,7 @@ package Spawn.Posix is
      (fd     : Interfaces.C.int;
       buf    : out Interfaces.C.char_array;
       buflen : Interfaces.C.size_t) return Interfaces.C.int
-     with Import, Convention => C, External_Name => "ptsname_r";
+     with Import, Convention => C, External_Name => "__ptsname_r";
 
    function setsid return Interfaces.C.int
      with Import, Convention => C, External_Name => "setsid";
