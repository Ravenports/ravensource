--- src/blkdev/blkdev.c.orig	2021-01-31 12:49:12 UTC
+++ src/blkdev/blkdev.c
@@ -7,7 +7,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
+#if !defined(__DragonFly__) && !defined(__FreeBSD__)
 #include <sys/sysmacros.h>
+#endif
 #include <unistd.h>
 #include <stdint.h>
 #include <stdio.h>
@@ -137,6 +139,7 @@ blkdev_get_size(int fd, unsigned long lo
 #endif /* FDGETPRM */
 
 #ifdef HAVE_SYS_DISKLABEL_H
+# if !defined(__DragonFly__) && !defined(__FreeBSD__)
 	{
 		/*
 		 * This code works for FreeBSD 4.11 i386, except for the full device
@@ -164,6 +167,7 @@ blkdev_get_size(int fd, unsigned long lo
 			}
 		}
 	}
+# endif
 #endif /* HAVE_SYS_DISKLABEL_H */
 
 	{
