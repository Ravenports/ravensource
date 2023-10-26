--- hw/xfree86/common/xf86Xinput.c.orig	2023-10-25 01:40:28 UTC
+++ hw/xfree86/common/xf86Xinput.c
@@ -1065,6 +1065,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
