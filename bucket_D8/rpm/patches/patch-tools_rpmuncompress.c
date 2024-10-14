--- tools/rpmuncompress.c.orig	2024-10-07 09:35:46 UTC
+++ tools/rpmuncompress.c
@@ -5,6 +5,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/wait.h>
 
 #include <archive.h>
 #include <archive_entry.h>
