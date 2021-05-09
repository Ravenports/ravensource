--- hw/ppc/mac_oldworld.c.orig	2021-04-29 17:18:58 UTC
+++ hw/ppc/mac_oldworld.c
@@ -63,6 +63,11 @@
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
