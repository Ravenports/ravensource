--- lib/libv4l1/v4l1compat.c.orig	2013-06-28 20:10:56 UTC
+++ lib/libv4l1/v4l1compat.c
@@ -29,7 +29,9 @@
 #include "../libv4lconvert/libv4lsyscall-priv.h" /* for __off_t */
 
 #include <sys/ioctl.h>
+#ifndef __sun__
 #include <sys/mman.h>
+#endif
 
 /* Check that open/read/mmap is not a define */
 #if defined open || defined read || defined mmap
