--- lib/local_filesys.cpp.orig	2026-10-23 14:05:39 UTC
+++ lib/local_filesys.cpp
@@ -16,6 +16,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <string.h>
+#include <limits.h>
 #include <utime.h>
 #endif
 
