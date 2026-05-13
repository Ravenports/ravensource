--- lib/procfs.c.orig	2026-04-01 09:52:48 UTC
+++ lib/procfs.c
@@ -8,6 +8,10 @@
 #include <unistd.h>
 #include <errno.h>
 
+#if defined __sun__
+#undef HAVE_SYS_VFS_H
+#endif
+
 #ifdef HAVE_SYS_VFS_H
 # include <sys/vfs.h>
 #endif
