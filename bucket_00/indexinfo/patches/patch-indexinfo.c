--- indexinfo.c.orig	2017-11-05 20:38:31 UTC
+++ indexinfo.c
@@ -211,6 +211,9 @@ parse_info_dir(int fd)
 #ifdef __linux__
 		if (_D_EXACT_NAMLEN(dp) < 5)
 			continue;
+#elif defined __sun__
+		if (dp->d_reclen - (offsetof(dirent_t, d_name[0])) < 5)
+			continue;
 #else
 		if (dp->d_namlen < 5)
 			continue;
