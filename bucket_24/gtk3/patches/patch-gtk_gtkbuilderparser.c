--- gtk/gtkbuilderparser.c.orig	2024-07-10 17:03:14 UTC
+++ gtk/gtkbuilderparser.c
@@ -1149,7 +1149,7 @@ end_element (GMarkupParseContext  *conte
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext  *context,
+XXXtext (GMarkupParseContext  *context,
       const gchar          *text,
       gsize                 text_len,
       gpointer              user_data,
@@ -1207,7 +1207,7 @@ free_info (CommonInfo *info)
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
 };
 
