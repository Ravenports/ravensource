--- gio/gunixmounts.c.orig	2024-12-11 22:21:22 UTC
+++ gio/gunixmounts.c
@@ -74,6 +74,10 @@ extern char* hasmntopt(const struct mnte
 #define O_BINARY 0
 #endif
 
+#ifdef __sun__
+#define mnt_opts	mnt_mntopts
+#endif
+
 #include "gunixmounts.h"
 #include "gfile.h"
 #include "gfilemonitor.h"
