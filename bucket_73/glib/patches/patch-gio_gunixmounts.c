--- gio/gunixmounts.c.orig	2022-11-24 12:29:05 UTC
+++ gio/gunixmounts.c
@@ -65,6 +65,10 @@
 #define O_BINARY 0
 #endif
 
+#ifdef __sun__
+#define mnt_opts	mnt_mntopts
+#endif
+
 #include "gunixmounts.h"
 #include "gfile.h"
 #include "gfilemonitor.h"
