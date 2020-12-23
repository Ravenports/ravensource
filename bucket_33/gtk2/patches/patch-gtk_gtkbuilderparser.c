--- gtk/gtkbuilderparser.c.orig	2020-12-18 05:29:40 UTC
+++ gtk/gtkbuilderparser.c
@@ -1051,7 +1051,7 @@ end_element (GMarkupParseContext *contex
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext *context,
+XXXtext (GMarkupParseContext *context,
       const gchar         *text,
       gsize                text_len,
       gpointer             user_data,
@@ -1106,7 +1106,7 @@ free_info (CommonInfo *info)
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
   NULL
 };
