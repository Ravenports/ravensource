--- src/scfb_driver.c.orig	2021-12-15 22:31:33 UTC
+++ src/scfb_driver.c
@@ -837,9 +837,11 @@ ScfbScreenInit(SCREEN_INIT_ARGS_DECL)
 		    "disabling DGA\n");
 #endif
 	if (fPtr->rotate) {
+#if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 24
 		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Enabling Driver Rotation, "
 		    "disabling RandR\n");
 		xf86DisableRandR();
+#endif
 		if (pScrn->bitsPerPixel == 24)
 			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
 			    "Rotation might be broken in 24 bpp\n");
