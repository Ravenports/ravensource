--- src/util/os_file.c.orig	2023-07-21 12:42:42 UTC
+++ src/util/os_file.c
@@ -28,6 +28,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
