--- lib/physmem-posix.c.orig	2024-02-24 23:11:10 UTC
+++ lib/physmem-posix.c
@@ -29,6 +29,10 @@
 #define OFF_MAX ((((off_t)1 << (sizeof(off_t) * CHAR_BIT - 2)) - 1) * 2 + 1)
 #endif
 
+#ifndef O_DSYNC
+#define O_DSYNC 0
+#endif
+
 struct physmem {
   int fd;
 };
