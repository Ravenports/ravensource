--- hw/xfree86/common/xf86Xinput.c.orig	2021-04-13 14:11:40 UTC
+++ hw/xfree86/common/xf86Xinput.c
@@ -874,7 +874,7 @@ xf86NewInputDevice(InputInfoPtr pInfo, D
 {
     InputDriverPtr drv = NULL;
     DeviceIntPtr dev = NULL;
-    Bool paused;
+    Bool paused = 0;
     int rval;
     char *path = NULL;
 
@@ -1037,6 +1037,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
