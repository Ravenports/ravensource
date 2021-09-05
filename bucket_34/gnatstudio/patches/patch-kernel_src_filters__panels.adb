--- kernel/src/filter_panels.adb.orig	2021-06-18 05:08:58 UTC
+++ kernel/src/filter_panels.adb
@@ -26,6 +26,7 @@ with Gdk.Event;                use Gdk.E
 with Gtk.GEntry;               use Gtk.GEntry;
 with Gtk.Menu_Item;            use Gtk.Menu_Item;
 with Gtk.Separator_Menu_Item;  use Gtk.Separator_Menu_Item;
+with Gtk.Main;
 
 with Gtkada.Handlers;          use Gtkada.Handlers;
 
@@ -65,8 +66,7 @@ package body Filter_Panels is
 
    procedure On_Pattern_Config_Menu
      (Self  : access GObject_Record'Class;
-      Pos   : Gtk_Entry_Icon_Position;
-      Event : Gdk_Event);
+      Pos   : Gtk_Entry_Icon_Position);
    --  Creates the popup menu to configure the filter settings.
 
    function On_Filter_Focus_Out
@@ -400,13 +400,13 @@ package body Filter_Panels is
 
    procedure On_Pattern_Config_Menu
       (Self  : access GObject_Record'Class;
-       Pos   : Gtk_Entry_Icon_Position;
-       Event : Gdk_Event)
+       Pos   : Gtk_Entry_Icon_Position)
    is
       pragma Unreferenced (Pos);  --  unreliable with gtk+ 3.8
       use Glib;
 
       Panel : constant Filter_Panel := Filter_Panel (Self);
+      Event : constant Gdk_Event := Gtk.Main.Get_Current_Event;
 
       procedure Func
         (Menu    : not null access Gtk_Menu_Record'Class;
@@ -425,7 +425,7 @@ package body Filter_Panels is
       end Func;
 
    begin
-      if Panel.Pattern.Get_Icon_Position (Event.Button) =
+      if Panel.Pattern.Get_Icon_Position (Event) =
         Gtk_Entry_Icon_Primary
       then
          Panel.Pattern_Config_Menu.Show_All;
