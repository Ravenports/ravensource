--- src/ucm/parser.c.orig	2026-01-13 07:12:40 UTC
+++ src/ucm/parser.c
@@ -3633,7 +3633,9 @@ static int filename_filter(const struct
 {
 	if (dirent == NULL)
 		return 0;
+#if !defined(__sun)
 	if (dirent->d_type == DT_DIR) {
+#endif
 		if (dirent->d_name[0] == '.') {
 			if (dirent->d_name[1] == '\0')
 				return 0;
@@ -3642,7 +3644,9 @@ static int filename_filter(const struct
 				return 0;
 		}
 		return 1;
+#if !defined(__sun)
 	}
+#endif
 	return 0;
 }
 
