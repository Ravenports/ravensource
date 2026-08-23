--- tools/rpmuncompress.cc.orig	2026-07-16 13:34:05 UTC
+++ tools/rpmuncompress.cc
@@ -5,6 +5,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/wait.h>
 
 #include <archive.h>
 #include <archive_entry.h>
