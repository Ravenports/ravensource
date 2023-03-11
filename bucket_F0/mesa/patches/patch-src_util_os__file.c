--- src/util/os_file.c.orig	2023-03-08 18:37:09 UTC
+++ src/util/os_file.c
@@ -25,6 +25,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
