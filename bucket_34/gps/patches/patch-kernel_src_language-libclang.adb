--- kernel/src/language-libclang.adb.orig	2017-05-12 17:58:17 UTC
+++ kernel/src/language-libclang.adb
@@ -304,7 +304,7 @@ package body Language.Libclang is
       --  Remove elements from the cache if > LRU_Size
 
       if Clang_Module_Id.LRU.Length >
-        Count_Type (LRU_Size_Preference.Get_Pref)
+        Count_Type (Integer'(LRU_Size_Preference.Get_Pref))
       then
          declare
             F : constant Unbounded_String := Clang_Module_Id.LRU.First_Element;
