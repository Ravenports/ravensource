--- src/util/os_file.c.orig	2025-12-04 06:02:48 UTC
+++ src/util/os_file.c
@@ -34,6 +34,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
