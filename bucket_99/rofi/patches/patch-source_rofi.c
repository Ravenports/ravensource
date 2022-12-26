--- source/rofi.c.orig	2022-08-09 13:47:23 UTC
+++ source/rofi.c
@@ -37,6 +37,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#if defined __FreeBSD__ || defined __NetBSD__
+#include <sys/stat.h>
+#endif
 #include <sysexits.h>
 #include <time.h>
 #include <unistd.h>
