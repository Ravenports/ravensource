--- avahi-core/fdutil.c.orig	2015-04-01 04:58:14 UTC
+++ avahi-core/fdutil.c
@@ -23,6 +23,7 @@
 
 #include <sys/select.h>
 #include <unistd.h>
+#include <string.h>
 #include <fcntl.h>
 #include <assert.h>
 
