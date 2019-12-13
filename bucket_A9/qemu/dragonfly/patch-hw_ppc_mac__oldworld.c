--- hw/ppc/mac_oldworld.c.orig	2019-12-12 18:20:47 UTC
+++ hw/ppc/mac_oldworld.c
@@ -61,6 +61,11 @@
 
 #define GRACKLE_BASE 0xfec00000
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static void fw_cfg_boot_set(void *opaque, const char *boot_device,
                             Error **errp)
 {
