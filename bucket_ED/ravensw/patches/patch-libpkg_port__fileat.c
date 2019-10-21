--- libpkg/port_fileat.c.orig	2019-07-23 16:09:40 UTC
+++ libpkg/port_fileat.c
@@ -88,7 +88,7 @@ file_chdir_unlock(int dfd)
 	file_at_dfd = -1;
 
 	if (dfd == AT_FDCWD)
-		return;
+		return(0);
 
 	if (saved_cwd[0] != '\0')
 		chdir(saved_cwd);
