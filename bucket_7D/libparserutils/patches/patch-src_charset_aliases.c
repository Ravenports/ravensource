--- src/charset/aliases.c.orig	2018-08-22 13:25:07 UTC
+++ src/charset/aliases.c
@@ -49,8 +49,12 @@ static int parserutils_charset_alias_mat
                 
                 if (key_left == 0)
                         break;
-                
+               
+#ifdef __NetBSD__
+                cmpret = tolower((int)*s_key) - *s_alias;
+#else 
                 cmpret = tolower(*s_key) - *s_alias;
+#endif
                 
                 if (cmpret != 0) {
                         return cmpret;
