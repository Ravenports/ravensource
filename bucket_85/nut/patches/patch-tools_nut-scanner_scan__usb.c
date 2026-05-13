--- tools/nut-scanner/scan_usb.c.orig	2026-03-22 20:48:48 UTC
+++ tools/nut-scanner/scan_usb.c
@@ -516,10 +516,16 @@ nutscan_device_t * nutscan_scan_usb(nuts
 		 * libusb_exit() should not be called unless libusb_init()
 		 * succeeded for same context.
 		 */
+#if defined(__DragonFly__) && __DragonFly_version < 600514
+		/* DragonFly BSD lacks 'struct libusb_version'. Skip the version check.
+         	 * To avoid the upstream libusb bug where libusb_exit() crashes after a 
+         	 * failed libusb_init(), we safely skip calling exit entirely here. */
+#else
 		const struct libusb_version	*ver = (*nut_usb_get_version)();
 
 		if (ver && (ver->major > 1 || (ver->major == 1 && ver->minor >= 24)))
 			(*nut_usb_exit)(NULL);
+#endif
 		upsdebug_with_errno(0, "Failed to init libusb 1.0");
 		/* nutscan_avail_usb = 0; */
 		return NULL;
