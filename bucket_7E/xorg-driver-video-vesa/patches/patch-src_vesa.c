--- src/vesa.c.orig	2022-12-09 20:27:18 UTC
+++ src/vesa.c
@@ -491,10 +491,12 @@ VESAPciProbe(DriverPtr drv, int entity_n
     if (pScrn != NULL) {
 	VESAPtr pVesa;
 
+#if !(defined(__FreeBSD__) || defined(__DragonFly__))
 	if (pci_device_has_kernel_driver(dev)) {
 	    ErrorF("vesa: Ignoring device with a bound kernel driver\n");
 	    return FALSE;
 	}
+#endif
 
 	pVesa = VESAGetRec(pScrn);
 	VESAInitScrn(pScrn);
