--- gl/lib/fdopendir.c.orig	2026-06-24 09:56:19 UTC
+++ gl/lib/fdopendir.c
@@ -216,9 +216,11 @@ fd_clone_opendir (int fd, struct saved_c
 
 # include <errno.h>
 # include <sys/stat.h>
+# include <dirent.h>
 
 # undef fdopendir
 
+extern DIR *fdopendir(int);
 /* Like fdopendir, but work around GNU/Hurd bug by validating FD.  */
 
 DIR *
