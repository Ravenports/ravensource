--- lib/local_filesys.cpp.orig	2025-12-10 15:59:22 UTC
+++ lib/local_filesys.cpp
@@ -15,6 +15,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <string.h>
+#include <limits.h>
 #include <utime.h>
 #endif
 
