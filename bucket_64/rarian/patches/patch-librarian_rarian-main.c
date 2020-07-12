--- librarian/rarian-main.c.orig	2008-09-01 18:40:21 UTC
+++ librarian/rarian-main.c
@@ -215,7 +215,7 @@ past:
     path = getenv ("XDG_DATA_DIRS");
 
     if (!path || !strcmp (path, "")) {
-        path = "/usr/local/share/:/usr/share/";
+        path = "/usr/local/share/";
     }
     cur_path = path;
 
