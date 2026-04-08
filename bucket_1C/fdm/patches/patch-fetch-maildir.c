--- fetch-maildir.c.orig	2023-01-09 11:20:17 UTC
+++ fetch-maildir.c
@@ -169,13 +169,15 @@ fetch_maildir_poll(struct account *a)
 		}
 
 		while ((dp = readdir(dirp)) != NULL) {
+#if defined(__sun)
+			if (fstatat(dirfd(dirp), dp->d_name, &sb, 0) == 0 &&
+			     S_ISREG(sb.st_mode)) {
+#else
 			if (dp->d_type == DT_REG) {
+#endif
 				data->total++;
 				continue;
 			}
-			if (dp->d_type != DT_UNKNOWN)
-				continue;
-
 			if (ppath(entry, sizeof entry, "%s/%s", path,
 			    dp->d_name) != 0) {
 				log_warn("%s: %s: printpath", a->name, path);
