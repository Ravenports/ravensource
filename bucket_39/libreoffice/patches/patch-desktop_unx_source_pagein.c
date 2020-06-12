--- desktop/unx/source/pagein.c.orig	2020-05-13 11:19:20 UTC
+++ desktop/unx/source/pagein.c
@@ -25,7 +25,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
+#ifdef LINUX
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 
 /* do_pagein */
