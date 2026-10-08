--- backend/usb-libusb.c.orig	2026-10-05 15:26:07 UTC
+++ backend/usb-libusb.c
@@ -1568,7 +1568,7 @@ open_device(usb_printer_t *printer,	/* I
   * works without the module attached.
   */
 
-  errcode = libusb_kernel_driver_active(printer->handle, printer->iface);
+  errcode = 0;
   if (errcode == 0)
     printer->usblp_attached = 0;
   else if (errcode == 1)
