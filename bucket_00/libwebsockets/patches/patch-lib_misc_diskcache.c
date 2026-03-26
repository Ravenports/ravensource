--- lib/misc/diskcache.c.orig	2026-03-17 16:35:25 UTC
+++ lib/misc/diskcache.c
@@ -280,6 +280,9 @@ lws_diskcache_trim(struct lws_diskcache_
 	size_t trimmed = 0;
 	struct dirent *de;
 	struct stat s;
+#if defined(__sun)
+	struct stat st;
+#endif
 	DIR *dir;
 
 	if (!lds->cache_subdir) {
@@ -316,14 +319,16 @@ lws_diskcache_trim(struct lws_diskcache_
 		if (!de)
 			break;
 
+		lws_snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, de->d_name);
+#if defined(__sun)
+		if (stat(filepath, &st) != 0 || !S_ISREG(st.st_mode))
+			continue;
+#else
 		if (de->d_type != DT_REG)
 			continue;
-
+#endif
 		lds->agg_file_count++;
 
-		lws_snprintf(filepath, sizeof(filepath), "%s/%s", dirpath,
-			     de->d_name);
-
 		fd = open(filepath, O_RDONLY);
 		if (fd < 0) {
 			lwsl_err("%s: cannot open %s\n", __func__, filepath);
