--- kernel/src/gtkada-search_entry.ads.orig
+++ kernel/src/gtkada-search_entry.ads
@@ -35,7 +35,7 @@
 
    function Get_Icon_Position
      (Self   : access Gtkada_Search_Entry_Record'Class;
-      Event  : Gdk_Event_Button) return Gtk_Entry_Icon_Position;
+      Event  : Gdk_Event) return Gtk_Entry_Icon_Position;
    --  Returns the icon which was clicked on.
    --  For some reason, gtk+ always seems to return the primary icon otherwise.
 
