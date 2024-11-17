--- gcc/ada/libgnat/s-dorepr.adb.orig	2024-08-01 08:17:13 UTC
+++ gcc/ada/libgnat/s-dorepr.adb
@@ -77,18 +77,28 @@ package body Product is
             end;
 
          when 53 =>
-            declare
-               Rep64 : aliased Interfaces.Unsigned_64;
-               Temp  : Num := N with Address => Rep64'Address;
-               pragma Annotate (CodePeer, Modified, Rep64);
+            if Num'Size > 64 then
+               declare
+                  Rep64 : Interfaces.Unsigned_64;
+               begin
+                  Rep64 := Interfaces.Unsigned_64 (N);
+                  Rep64 := Rep64 and 16#FFFFFFFFF8000000#;
+                  X := Num (Rep64);
+               end;
+            else
+               declare
+                  Rep64 : aliased Interfaces.Unsigned_64;
+                  Temp  : Num := N with Address => Rep64'Address;
+                  pragma Annotate (CodePeer, Modified, Rep64);
 
-            begin
-               --  Mask out the low 27 bits
+               begin
+                  --  Mask out the low 27 bits
 
-               Rep64 := Rep64 and 16#FFFFFFFFF8000000#;
+                  Rep64 := Rep64 and 16#FFFFFFFFF8000000#;
 
-               X := Temp;
-            end;
+                  X := Temp;
+               end;
+            end if;
 
          when 64 =>
             declare
