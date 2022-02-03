--- gst/tcp/gstmultifdsink.c.orig	2022-02-02 15:06:16 UTC
+++ gst/tcp/gstmultifdsink.c
@@ -107,6 +107,9 @@
 #include <gst/gst-i18n-plugin.h>
 
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
