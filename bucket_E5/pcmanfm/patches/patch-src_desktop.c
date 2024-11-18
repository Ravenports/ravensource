--- src/desktop.c.orig	2021-02-02 19:21:05 UTC
+++ src/desktop.c
@@ -1267,7 +1267,7 @@ static AtkObject *fm_desktop_accessible_
         item = items->data;
         if (item->item->is_selected)
             if (i-- == 0)
-                return g_object_ref(item);
+                return (AtkObject *)g_object_ref(item);
     }
     return NULL;
 }
@@ -1454,7 +1454,7 @@ static AtkObject *fm_desktop_accessible_
     item = g_list_nth_data(priv->items, index);
     if (!item)
         return NULL;
-    return g_object_ref(item);
+    return (AtkObject *)g_object_ref(item);
 }
 
 static void fm_desktop_accessible_initialize(AtkObject *accessible, gpointer data)
