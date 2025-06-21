--- lib/fbsd-device.c.orig	2025-06-21 16:06:20 UTC
+++ lib/fbsd-device.c
@@ -25,7 +25,7 @@
 #  endif
 #endif
 
-#if __FreeBSD_version < 430000 && !defined(__DragonFly__)
+#if __FreeBSD_version < 430000 && !defined(__DragonFly__) && !defined(__MidnightBSD__)
 #  include <pci/pcivar.h>
 #  include <pci/pci_ioctl.h>
 #else
@@ -261,7 +261,7 @@ fbsd_read(struct pci_dev *d, int pos, by
   if (pos >= 4096)
     return 0;
 
-#if __FreeBSD_version >= 700053 || defined(__DragonFly__)
+#if __FreeBSD_version >= 700053 || defined(__DragonFly__) || defined(__MidnightBSD__)
   pi.pi_sel.pc_domain = d->domain;
 #else
   if (d->domain)
@@ -313,7 +313,7 @@ fbsd_write(struct pci_dev *d, int pos, b
   if (pos >= 4096)
     return 0;
 
-#if __FreeBSD_version >= 700053 || defined(__DragonFly__)
+#if __FreeBSD_version >= 700053 || defined(__DragonFly__) || defined(__MidnightBSD__)
   pi.pi_sel.pc_domain = d->domain;
 #else
   if (d->domain)
