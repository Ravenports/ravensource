--- src//general.c.orig	2024-08-19 16:28:44 UTC
+++ src//general.c
@@ -7,7 +7,11 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <glob.h>
+#if defined(__sun)
+#include <fcntl.h>
+#else
 #include <sys/fcntl.h>
+#endif
 #include <sys/stat.h>
 
 #include "i3status.h"
