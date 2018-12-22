--- gio/gunixmounts.c.orig	2018-12-18 14:51:13 UTC
+++ gio/gunixmounts.c
@@ -63,6 +63,10 @@
 #define O_BINARY 0
 #endif
 
+#ifdef __sun__
+#define mnt_opts	mnt_mntopts
+#endif
+
 #include "gunixmounts.h"
 #include "glocalfileprivate.h"
 #include "gfile.h"
