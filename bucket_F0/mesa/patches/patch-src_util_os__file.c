--- src/util/os_file.c.orig	2022-08-17 16:53:25 UTC
+++ src/util/os_file.c
@@ -25,6 +25,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
