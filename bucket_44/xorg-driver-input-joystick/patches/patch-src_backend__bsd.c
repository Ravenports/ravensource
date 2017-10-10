--- src/backend_bsd.c.orig	2014-03-20 02:14:06 UTC
+++ src/backend_bsd.c
@@ -42,10 +42,16 @@
 #include <xf86_OSproc.h>
 
 #include <usbhid.h>
+#ifdef __DragonFly__
+#include <bus/u4b/usb.h>
+#include <bus/u4b/usbhid.h>
+#include <bus/u4b/usb_ioctl.h>
+#else
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
-#ifdef HAVE_DEV_USB_USB_IOCTL_H
+# ifdef HAVE_DEV_USB_USB_IOCTL_H
     #include <dev/usb/usb_ioctl.h>
+# endif
 #endif
 
 #include "jstk.h"
