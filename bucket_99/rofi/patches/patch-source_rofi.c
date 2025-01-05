--- source/rofi.c.orig	2024-12-31 22:52:29 UTC
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
