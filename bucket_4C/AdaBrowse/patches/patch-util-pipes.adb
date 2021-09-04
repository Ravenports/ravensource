--- util-pipes.adb.orig	2021-09-04 15:38:31 UTC
+++ util-pipes.adb
@@ -132,16 +132,8 @@ package body Util.Pipes is
       --  <stdio.h>, the ISO C standard requires that they also be available
       --  as real functions. Hence we may import them directly.
 
-      pragma Linker_Options ("util-nl.o");
-
-      function Get_NL return Interfaces.C.int;
-      pragma Import (C, Get_NL, "get_newline");
-
-      New_Line : constant Interfaces.C.int := Get_NL;
-      --  '\n' is replaced at compile-time by a C compiler. Hence we cannot
-      --  use fputs (To_C ("\n")) to generate whatever C expects as a newline.
-      --  Therefore, we have a little C wrapper which just returns '\n', and
-      --  we remember that value here.
+      New_Line : constant Interfaces.C.int := Interfaces.C.char'Pos
+        (Interfaces.C.nul);
 
    end Std_IO;
 
