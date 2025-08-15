--- gtk/gtkbuilderparser.c.orig	2025-03-05 23:31:26 UTC
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
 
