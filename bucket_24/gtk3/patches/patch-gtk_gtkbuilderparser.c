--- gtk/gtkbuilderparser.c.orig	2020-02-03 11:45:12 UTC
+++ gtk/gtkbuilderparser.c
@@ -1148,7 +1148,7 @@ end_element (GMarkupParseContext  *conte
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext  *context,
+XXXtext (GMarkupParseContext  *context,
       const gchar          *text,
       gsize                 text_len,
       gpointer              user_data,
@@ -1206,7 +1206,7 @@ free_info (CommonInfo *info)
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
 };
 
