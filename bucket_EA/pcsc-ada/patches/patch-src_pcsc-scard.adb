--- src/pcsc-scard.adb.orig	2016-07-08 13:35:03 UTC
+++ src/pcsc-scard.adb
@@ -305,7 +305,6 @@ package body PCSC.SCard is
    -------------------------------------------------------------------------
 
    function First_Item (Set : Reader_States_Set) return Reader_State is
-      use type Ada.Containers.Count_Type;
    begin
       return Set.Data.First_Element;
    end First_Item;
@@ -517,7 +516,6 @@ package body PCSC.SCard is
    -------------------------------------------------------------------------
 
    function Last_Item (Set : Reader_States_Set) return Reader_State is
-      use type Ada.Containers.Count_Type;
    begin
       return Set.Data.Last_Element;
    end Last_Item;
