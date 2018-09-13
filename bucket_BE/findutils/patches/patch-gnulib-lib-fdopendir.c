--- gl/lib/fdopendir.c.orig	2015-12-24 16:41:42 UTC
+++ gl/lib/fdopendir.c
@@ -191,9 +191,11 @@ fd_clone_opendir (int fd, struct saved_c
 
 # include <errno.h>
 # include <sys/stat.h>
+# include <dirent.h>
 
 # undef fdopendir
 
+extern DIR *fdopendir(int);
 /* Like fdopendir, but work around GNU/Hurd bug by validating FD.  */
 
 DIR *
