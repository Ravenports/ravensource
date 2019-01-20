--- erts/etc/unix/run_erl.c.orig	2019-01-15 18:35:10 UTC
+++ erts/etc/unix/run_erl.c
@@ -81,9 +81,6 @@
 #ifdef HAVE_LIBUTIL_H
 #  include <libutil.h>
 #endif
-#ifdef HAVE_UTIL_H
-#  include <util.h>
-#endif
 #ifdef HAVE_SYS_IOCTL_H
 #  include <sys/ioctl.h>
 #endif
