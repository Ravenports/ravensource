--- src/util/os_file.c.orig	2025-01-22 18:12:23 UTC
+++ src/util/os_file.c
@@ -28,6 +28,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
