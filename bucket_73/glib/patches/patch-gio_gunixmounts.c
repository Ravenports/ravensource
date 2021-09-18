--- gio/gunixmounts.c.orig	2021-09-17 10:17:56 UTC
+++ gio/gunixmounts.c
@@ -63,6 +63,10 @@
 #define O_BINARY 0
 #endif
 
+#ifdef __sun__
+#define mnt_opts	mnt_mntopts
+#endif
+
 #include "gunixmounts.h"
 #include "gfile.h"
 #include "gfilemonitor.h"
