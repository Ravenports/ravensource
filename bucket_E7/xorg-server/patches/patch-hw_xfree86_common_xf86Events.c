--- hw/xfree86/common/xf86Events.c.orig	2021-12-15 13:51:50 UTC
+++ hw/xfree86/common/xf86Events.c
@@ -383,6 +383,7 @@ xf86VTLeave(void)
         xf86GPUScreens[i]->LeaveVT(xf86GPUScreens[i]);
 
     if (systemd_logind_controls_session()) {
+#ifdef XSERVER_PLATFORM_BUS
         for (i = 0; i < xf86_num_platform_devices; i++) {
             if (xf86_platform_devices[i].flags & XF86_PDEV_SERVER_FD) {
                 int major, minor;
@@ -391,6 +392,7 @@ xf86VTLeave(void)
                 systemd_logind_drop_master(major, minor);
             }
         }
+#endif
     }
 
     if (!xf86VTSwitchAway())
