--- hw/xfree86/common/xf86Globals.c.orig	2017-12-20 20:32:33 UTC
+++ hw/xfree86/common/xf86Globals.c
@@ -122,7 +122,8 @@ xf86InfoRec xf86Info = {
     .pmFlag = TRUE,
     .disableRandR = FALSE,
     .randRFrom = X_DEFAULT,
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+	defined(CONFIG_DEVD)
     .forceInputDevices = FALSE,
     .autoAddDevices = TRUE,
     .autoEnableDevices = TRUE,
