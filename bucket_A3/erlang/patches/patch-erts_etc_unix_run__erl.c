--- erts/etc/unix/run_erl.c.orig	2025-06-13 14:54:33 UTC
+++ erts/etc/unix/run_erl.c
@@ -83,7 +83,7 @@
 #ifdef HAVE_LIBUTIL_H
 #  include <libutil.h>
 #endif
-#ifdef HAVE_UTIL_H
+#ifdef __NetBSD__
 #  include <util.h>
 #endif
 #ifdef HAVE_SYS_IOCTL_H
