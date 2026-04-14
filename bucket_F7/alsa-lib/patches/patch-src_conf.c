--- src/conf.c.orig	2026-01-13 07:12:40 UTC
+++ src/conf.c
@@ -4103,8 +4103,10 @@ static int config_filename_filter(const
 
 	if (dirent == NULL)
 		return 0;
+#if !defined(__sun)
 	if (dirent->d_type == DT_DIR)
 		return 0;
+#endif
 
 	flen = strlen(dirent->d_name);
 	if (flen <= 5)
