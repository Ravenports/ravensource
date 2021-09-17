--- gst/tcp/gstmultifdsink.c.orig	2021-09-08 19:02:22 UTC
+++ gst/tcp/gstmultifdsink.c
@@ -107,6 +107,9 @@
 #include <gst/gst-i18n-plugin.h>
 
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
