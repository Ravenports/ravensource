--- objects/GRAFCET/boolequation.c.orig	2014-08-24 15:46:01 UTC
+++ objects/GRAFCET/boolequation.c
@@ -58,7 +58,7 @@ struct _Block {
 
 
 /* utility */
-inline static gboolean isspecial(gunichar c) 
+inline static gboolean dia_isspecial(gunichar c) 
 {
   switch (c) {
   case '!':
@@ -136,7 +136,7 @@ static Block *textblock_create(const gch
     gchar *p1;
     c = g_utf8_get_char(*str);
     p1 = g_utf8_next_char(*str);
-    if (isspecial(c)) break;
+    if (dia_isspecial(c)) break;
     *str = p1;
   }
   
