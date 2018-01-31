--- lib/libv4l2/v4l2convert.c.orig	2015-05-06 19:24:59 UTC
+++ lib/libv4l2/v4l2convert.c
@@ -31,7 +31,9 @@
 #include <fcntl.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifndef __sun__
 #include <sys/mman.h>
+#endif
 #include "../libv4lconvert/libv4lsyscall-priv.h"
 #include <linux/videodev2.h>
 #include <libv4l2.h>
