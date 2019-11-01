--- libpkg/port_fileat.c.orig	2019-07-23 16:09:40 UTC
+++ libpkg/port_fileat.c
@@ -88,7 +88,7 @@ file_chdir_unlock(int dfd)
 	file_at_dfd = -1;
 
 	if (dfd == AT_FDCWD)
-		return;
+		return(0);
 
 	if (saved_cwd[0] != '\0')
 		chdir(saved_cwd);
@@ -170,11 +170,15 @@ port_fchmodat(int fd, const char* path,
 	if ((ret = file_chdir_lock(fd) != 0))
 		return(ret);
 
+#if defined(__sun__) || defined(__linux__)
+	ret = chmod(path, mode);
+#else
 	if (flag & AT_SYMLINK_NOFOLLOW) {
 		ret = lchmod(path, mode);
 	} else {
 		ret = chmod(path, mode);
 	}
+#endif
 
 	file_chdir_unlock(fd);
 	return(ret);
