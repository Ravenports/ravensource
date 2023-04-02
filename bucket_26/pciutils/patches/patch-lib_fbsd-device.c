--- lib/fbsd-device.c.orig	2022-11-20 12:06:14 UTC
+++ lib/fbsd-device.c
@@ -23,7 +23,7 @@
 #  endif
 #endif
 
-#if __FreeBSD_version < 430000 && !defined(__DragonFly__)
+#if __FreeBSD_version < 430000 && !defined(__DragonFly__) && !defined(__MidnightBSD__)
 #  include <pci/pcivar.h>
 #  include <pci/pci_ioctl.h>
 #else
@@ -259,7 +259,7 @@ fbsd_read(struct pci_dev *d, int pos, by
   if (pos >= 4096)
     return 0;
 
-#if __FreeBSD_version >= 700053 || defined(__DragonFly__)
+#if __FreeBSD_version >= 700053 || defined(__DragonFly__) || defined(__MidnightBSD__)
   pi.pi_sel.pc_domain = d->domain;
 #else
   if (d->domain)
@@ -311,7 +311,7 @@ fbsd_write(struct pci_dev *d, int pos, b
   if (pos >= 4096)
     return 0;
 
-#if __FreeBSD_version >= 700053 || defined(__DragonFly__)
+#if __FreeBSD_version >= 700053 || defined(__DragonFly__) || defined(__MidnightBSD__)
   pi.pi_sel.pc_domain = d->domain;
 #else
   if (d->domain)
