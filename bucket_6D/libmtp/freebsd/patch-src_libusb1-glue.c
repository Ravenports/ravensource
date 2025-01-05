--- src/libusb1-glue.c.orig	2024-11-20 13:47:46.000000000 +0100
+++ src/libusb1-glue.c	2025-01-05 21:55:34.942857000 +0100
@@ -153,7 +153,7 @@
    * We use the same level debug between MTP and USB.
    */
   if (libusb1_initialized)
-     return LIBMTP_ERROR_NONE;
+    libusb_exit(NULL);
 
   if (libusb_init(&libmtp_libusb_context) < 0) {
     LIBMTP_ERROR("Libusb1 init failed\n");
@@ -163,8 +163,8 @@
   libusb1_initialized = 1;
 
   if ((LIBMTP_debug & LIBMTP_DEBUG_USB) != 0)
-    /*libusb_set_debug(libmtp_libusb_context,9);*/
-    libusb_set_option(libmtp_libusb_context, LIBUSB_OPTION_LOG_LEVEL,  LIBUSB_LOG_LEVEL_DEBUG ); /* highest level */
+    libusb_set_debug(libmtp_libusb_context,9);
+    // libusb_set_option(libmtp_libusb_context, LIBUSB_OPTION_LOG_LEVEL,  LIBUSB_LOG_LEVEL_DEBUG ); /* highest level */
   return LIBMTP_ERROR_NONE;
 }
 
