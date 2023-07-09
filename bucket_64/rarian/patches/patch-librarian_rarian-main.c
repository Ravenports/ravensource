--- librarian/rarian-main.c.orig	2023-05-06 00:02:46 UTC
+++ librarian/rarian-main.c
@@ -207,7 +207,7 @@ past:
     path = getenv("XDG_DATA_DIRS");
 
     if (!path || !strcmp(path, "")) {
-        path = "/usr/local/share/:/usr/share/";
+        path = "/usr/local/share/";
     }
     scan_dirs = rrn_str_split(path, ':');
 
