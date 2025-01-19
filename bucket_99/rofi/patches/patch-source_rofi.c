--- source/rofi.c.orig	2025-01-16 17:25:35 UTC
+++ source/rofi.c
@@ -38,6 +38,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#if defined __FreeBSD__ || defined __NetBSD__
+#include <sys/stat.h>
+#endif
 #include <sysexits.h>
 #include <time.h>
 #include <unistd.h>
