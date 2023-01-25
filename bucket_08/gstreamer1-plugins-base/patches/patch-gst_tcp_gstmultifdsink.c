--- gst/tcp/gstmultifdsink.c.orig	2023-01-23 19:29:34 UTC
+++ gst/tcp/gstmultifdsink.c
@@ -107,6 +107,9 @@
 #include <glib/gi18n-lib.h>
 
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
