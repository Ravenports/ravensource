--- hw/ppc/mac_oldworld.c.orig	2020-04-28 16:49:24 UTC
+++ hw/ppc/mac_oldworld.c
@@ -60,6 +60,11 @@
 
 #define GRACKLE_BASE 0xfec00000
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static void fw_cfg_boot_set(void *opaque, const char *boot_device,
                             Error **errp)
 {
