--- kernel/src/gps-search-gui.adb.orig	2017-05-12 17:58:17 UTC
+++ kernel/src/gps-search-gui.adb
@@ -740,7 +740,8 @@ package body GPS.Search.GUI is
       B.Pack_Start (Label, Expand => False);
 
       Gtk_New (Spin, Min => 2.0, Max => 20.0, Step => 1.0);
-      Spin.Set_Value (Gdouble (Pref_Proposals_Per_Provider.Get_Pref));
+      Spin.Set_Value (Gdouble
+        (Integer'(Pref_Proposals_Per_Provider.Get_Pref)));
       B.Pack_Start (Spin, Expand => False);
 
       Kernel_Callback.Connect
