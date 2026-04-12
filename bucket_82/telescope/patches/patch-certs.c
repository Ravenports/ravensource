--- certs.c.orig	2025-05-10 13:20:51 UTC
+++ certs.c
@@ -198,6 +198,10 @@ certs_init(const char *certfile)
 	char	*line = NULL;
 	size_t	 linesize = 0;
 	ssize_t	 linelen;
+#if defined(__sun)
+	struct stat st;
+	char path[PATH_MAX];
+#endif
 
 	id_cap = 8;
 	if ((identities = calloc(id_cap, sizeof(*identities))) == NULL)
@@ -207,8 +211,14 @@ certs_init(const char *certfile)
 		return (-1);
 
 	while ((dp = readdir(certdir)) != NULL) {
+#if defined(__sun)
+		snprintf(path, sizeof(path), "%s/%s", cert_dir, dp->d_name);
+		if (stat(path, &st) != 0 || !S_ISREG(st.st_mode))
+			continue;
+#else
 		if (dp->d_type != DT_REG)
 			continue;
+#endif
 		if (push_identity(dp->d_name) == -1) {
 			closedir(certdir);
 			return (-1);
