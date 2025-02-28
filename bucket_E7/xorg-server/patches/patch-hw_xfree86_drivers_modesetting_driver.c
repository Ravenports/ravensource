--- hw/xfree86/drivers/modesetting/driver.c.orig	2024-12-17 17:51:31 UTC
+++ hw/xfree86/drivers/modesetting/driver.c
@@ -925,8 +925,12 @@ try_enable_glamor(ScrnInfoPtr pScrn)
     modesettingPtr ms = modesettingPTR(pScrn);
     const char *accel_method_str = xf86GetOptValString(ms->drmmode.Options,
                                                        OPTION_ACCEL_METHOD);
+#if defined(__DragonFly__)
+    Bool do_glamor = FALSE;
+#else
     Bool do_glamor = (!accel_method_str ||
                       strcmp(accel_method_str, "glamor") == 0);
+#endif
 
     ms->drmmode.glamor = FALSE;
 
