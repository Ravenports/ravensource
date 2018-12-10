--- backend/usb-libusb.c.orig	2018-12-07 19:41:56 UTC
+++ backend/usb-libusb.c
@@ -1440,7 +1440,7 @@ open_device(usb_printer_t *printer,	/* I
   * works without the module attached.
   */
 
-  errcode = libusb_kernel_driver_active(printer->handle, printer->iface);
+  errcode = 0;
   if (errcode == 0)
     printer->usblp_attached = 0;
   else if (errcode == 1)
