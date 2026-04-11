--- src/print_file_contents.c.orig	2024-08-19 16:28:44 UTC
+++ src/print_file_contents.c
@@ -7,7 +7,11 @@
 #include <yajl/yajl_version.h>
 #include <sys/types.h>
 
+#if defined(__sun)
+#include <fcntl.h>
+#else
 #include <sys/fcntl.h>
+#endif
 #include <unistd.h>
 #include <errno.h>
 #include "i3status.h"
