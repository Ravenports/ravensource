--- gl/lib/fdopendir.c.orig	2022-01-03 23:22:27 UTC
+++ gl/lib/fdopendir.c
@@ -227,9 +227,11 @@ fd_clone_opendir (int fd, struct saved_c
 
 # include <errno.h>
 # include <sys/stat.h>
+# include <dirent.h>
 
 # undef fdopendir
 
+extern DIR *fdopendir(int);
 /* Like fdopendir, but work around GNU/Hurd bug by validating FD.  */
 
 DIR *
