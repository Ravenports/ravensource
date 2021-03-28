--- src/util/os_file.c.orig	2021-03-24 22:32:52 UTC
+++ src/util/os_file.c
@@ -25,6 +25,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
