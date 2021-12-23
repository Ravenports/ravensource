--- hw/ppc/mac_oldworld.c.orig	2021-12-14 20:42:02 UTC
+++ hw/ppc/mac_oldworld.c
@@ -61,6 +61,11 @@
 #define PROM_BASE 0xffc00000
 #define PROM_SIZE (4 * MiB)
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static void fw_cfg_boot_set(void *opaque, const char *boot_device,
                             Error **errp)
 {
