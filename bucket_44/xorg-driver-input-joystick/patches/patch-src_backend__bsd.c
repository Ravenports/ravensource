--- src/backend_bsd.c.orig	2022-12-09 00:09:50 UTC
+++ src/backend_bsd.c
@@ -42,6 +42,11 @@
 #include <xf86_OSproc.h>
 
 #include <usbhid.h>
+#ifdef __DragonFly__
+#include <bus/u4b/usb.h>
+#include <bus/u4b/usbhid.h>
+#include <bus/u4b/usb_ioctl.h>
+#else
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 #ifdef HAVE_DEV_HID_HID_H
@@ -50,6 +55,7 @@
 #ifdef HAVE_DEV_USB_USB_IOCTL_H
     #include <dev/usb/usb_ioctl.h>
 #endif
+#endif /* !dragonfly */
 
 #include "jstk.h"
 #include "backend_bsd.h"
