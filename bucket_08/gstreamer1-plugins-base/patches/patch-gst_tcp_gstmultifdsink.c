--- gst/tcp/gstmultifdsink.c.orig	2024-03-21 20:47:53 UTC
+++ gst/tcp/gstmultifdsink.c
@@ -107,6 +107,9 @@
 #include <glib/gi18n-lib.h>
 
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
