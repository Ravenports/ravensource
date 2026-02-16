--- drivers/libusb1.c.orig	2025-08-06 15:00:53 UTC
+++ drivers/libusb1.c
@@ -53,7 +53,19 @@ static void nut_libusb_close(libusb_devi
  */
 void nut_usb_addvars(void)
 {
+#if defined(__DragonFly__) && __DragonFly_version < 600514
+	const struct libusb_version {
+		const uint16_t major;
+		const uint16_t minor;
+		const uint16_t micro;
+	} _v = {
+		.major = 1,
+		.minor = 0,
+		.micro = 0,
+	}, *v = &_v;
+#else
 	const struct libusb_version	*v = libusb_get_version();
+#endif
 
 	/* allow -x vendor=X, vendorid=X, product=X, productid=X, serial=X */
 	addvar(VAR_VALUE, "vendor", "Regular expression to match UPS Manufacturer string");
