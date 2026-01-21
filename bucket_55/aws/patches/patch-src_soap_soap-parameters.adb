Make this compile on GCC 14 (This is clearly written for GCC 15)

--- src/soap/soap-parameters.adb.orig	2025-09-18 19:54:11 UTC
+++ src/soap/soap-parameters.adb
@@ -46,7 +46,7 @@ package body SOAP.Parameters is
 
    function "+" (O : Types.Object'Class) return List is
    begin
-      return [Types."+" (O)];
+      return (Set.To_Vector (Types."+" (O), Length => 1) with null record);
    end "+";
 
    --------------
@@ -386,8 +386,12 @@ package body SOAP.Parameters is
    -------------
 
    function To_List (Set : Types.Object_Set) return List is
+      Result : List;
    begin
-      return [for E of Set => E];
+      for E of Set loop
+         Result.Append (E);
+      end loop;
+      return Result;
    end To_List;
 
 end SOAP.Parameters;
