--- gvd/src/gvd-canvas.adb.orig	2017-05-12 17:58:17 UTC
+++ gvd/src/gvd-canvas.adb
@@ -735,9 +735,11 @@ package body GVD.Canvas is
       begin
          if Item.all in Display_Item_Record'Class then
             Display_Item (Item).Set_Width_Range
-              (Max => (Unit_Pixels, Gdouble (Max_Item_Width.Get_Pref)));
+              (Max => (Unit_Pixels,
+                Gdouble (Integer'(Max_Item_Width.Get_Pref))));
             Display_Item (Item).Set_Height_Range
-              (Max => (Unit_Pixels, Gdouble (Max_Item_Height.Get_Pref)));
+              (Max => (Unit_Pixels,
+                Gdouble (Integer'(Max_Item_Height.Get_Pref))));
          end if;
       end Resize_Item;
 
@@ -2000,9 +2002,11 @@ package body GVD.Canvas is
       Item.Update_Display;
 
       Item.Set_Width_Range
-        (Max => (Unit_Pixels, Gdouble (Max_Item_Width.Get_Pref)));
+        (Max => (Unit_Pixels,
+          Gdouble (Integer'(Max_Item_Width.Get_Pref))));
       Item.Set_Height_Range
-        (Max => (Unit_Pixels, Gdouble (Max_Item_Height.Get_Pref)));
+        (Max => (Unit_Pixels,
+          Gdouble (Integer'(Max_Item_Height.Get_Pref))));
 
       if Get_Detect_Aliases (Debugger) then
          Recompute_All_Aliases (Debugger, False);
