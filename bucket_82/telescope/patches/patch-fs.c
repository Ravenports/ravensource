--- fs.c.orig	2025-05-10 13:20:51 UTC
+++ fs.c
@@ -91,6 +91,10 @@ send_dir(struct tab *tab, const char *pa
 	struct dirent	**names;
 	int		(*selector)(const struct dirent *) = select_non_dot;
 	int		  i, len;
+#if defined(__sun)
+	struct stat	st;
+	char fullpath[PATH_MAX];
+#endif
 
 #if notyet
 	/*
@@ -119,7 +123,12 @@ send_dir(struct tab *tab, const char *pa
 	for (i = 0; i < len; ++i) {
 		const char *sufx = "";
 
+#if defined(__sun)
+		snprintf(fullpath, sizeof(fullpath), "%s/%s", path, names[i]->d_name);
+		if (stat(fullpath, &st) == 0 && S_ISDIR(st.st_mode))
+#else
 		if (names[i]->d_type == DT_DIR)
+#endif
 			sufx = "/";
 
 		parser_parsef(buffer, "=> %s%s\n", names[i]->d_name, sufx);
