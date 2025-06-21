--- hw/xfree86/drivers/modesetting/driver.c.orig	2025-06-18 16:25:56 UTC
+++ hw/xfree86/drivers/modesetting/driver.c
@@ -964,8 +964,12 @@ try_enable_glamor(ScrnInfoPtr pScrn)
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
 
