--- src/vmware.c.orig	2023-01-24 02:52:01 UTC
+++ src/vmware.c
@@ -381,7 +381,7 @@ VMWAREPreInit(ScrnInfoPtr pScrn, int fla
                    "No supported VMware SVGA found (read ID 0x%08x).\n", id);
         return FALSE;
     }
-    pVMWARE->suspensionSavedRegId = id;
+    pVMWARE->SavedReg.svga_reg_id = id;
 
 #if !XSERVER_LIBPCIACCESS
     pVMWARE->PciTag = pciTag(pVMWARE->PciInfo->bus, pVMWARE->PciInfo->device,
