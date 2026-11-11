--- avahi-core/fdutil.c.orig	2026-06-25 12:51:26 UTC
+++ avahi-core/fdutil.c
@@ -23,6 +23,7 @@
 
 #include <sys/select.h>
 #include <unistd.h>
+#include <string.h>
 #include <fcntl.h>
 #include <assert.h>
 
