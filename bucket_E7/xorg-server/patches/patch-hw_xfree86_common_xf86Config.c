--- hw/xfree86/common/xf86Config.c.orig	2022-12-19 10:53:03 UTC
+++ hw/xfree86/common/xf86Config.c
@@ -1279,13 +1279,16 @@ checkCoreInputDevices(serverLayoutPtr se
     }
 
     if (!xf86Info.forceInputDevices && !(foundPointer && foundKeyboard)) {
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+		defined(CONFIG_DEVD)
         const char *config_backend;
 
 #if defined(CONFIG_HAL)
         config_backend = "HAL";
 #elif defined(CONFIG_UDEV)
         config_backend = "udev";
+#elif defined(CONFIG_DEVD)
+        config_backend = "devd";
 #else
         config_backend = "wscons";
 #endif
