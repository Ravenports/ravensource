--- libgnucash/app-utils/guile-util.c.orig	2018-04-14 23:51:51 UTC
+++ libgnucash/app-utils/guile-util.c
@@ -1095,6 +1095,8 @@ gnc_parse_time_to_time64 (const gchar *s
 
     g_return_val_if_fail(s && format, -1);
 
+    bzero(&tm, sizeof(tm));
+
     if (!strptime(s, format, &tm))
         return -1;
 
