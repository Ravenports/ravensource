--- hw/ppc/mac_oldworld.c.orig	2026-08-27 12:23:32 UTC
+++ hw/ppc/mac_oldworld.c
@@ -67,6 +67,11 @@
 
 #define GRACKLE_BASE 0xfec00000
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static void fw_cfg_boot_set(void *opaque, const char *boot_device,
                             Error **errp)
 {
