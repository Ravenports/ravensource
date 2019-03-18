--- lib/dpkg/dir.c.orig	2018-12-29 11:21:15 UTC
+++ lib/dpkg/dir.c
@@ -45,7 +45,11 @@ dir_sync(DIR *dir, const char *path)
 {
 	int fd;
 
+#ifdef __sun__
+	fd = dir->dd_fd;
+#else
 	fd = dirfd(dir);
+#endif
 	if (fd < 0)
 		ohshite(_("unable to get file descriptor for directory '%s'"),
 		        path);
