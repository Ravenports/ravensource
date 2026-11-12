--- source/rofi.c.orig	2026-11-10 17:07:26 UTC
+++ source/rofi.c
@@ -39,6 +39,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#if defined __FreeBSD__ || defined __NetBSD__
+#include <sys/stat.h>
+#endif
 #include <sysexits.h>
 #include <time.h>
 #include <unistd.h>
