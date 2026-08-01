--- gio/gunixmounts.c.orig	2026-06-25 13:35:18 UTC
+++ gio/gunixmounts.c
@@ -75,6 +75,10 @@ extern char* hasmntopt(const struct mnte
 #define O_BINARY 0
 #endif
 
+#ifdef __sun__
+#define mnt_opts	mnt_mntopts
+#endif
+
 #include "gunixmounts.h"
 #include "gunixmounts-private.h"
 #include "gfile.h"
