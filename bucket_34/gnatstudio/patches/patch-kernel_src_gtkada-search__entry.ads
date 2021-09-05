--- kernel/src/gtkada-search_entry.ads.orig	2021-06-15 05:19:41 UTC
+++ kernel/src/gtkada-search_entry.ads
@@ -35,7 +35,7 @@ package Gtkada.Search_Entry is
 
    function Get_Icon_Position
      (Self   : access Gtkada_Search_Entry_Record'Class;
-      Event  : Gdk_Event_Button) return Gtk_Entry_Icon_Position;
+      Event  : Gdk_Event) return Gtk_Entry_Icon_Position;
    --  Returns the icon which was clicked on.
    --  For some reason, gtk+ always seems to return the primary icon otherwise.
 
