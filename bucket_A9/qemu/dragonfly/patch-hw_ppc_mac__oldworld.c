--- hw/ppc/mac_oldworld.c.orig	2020-12-08 16:59:44 UTC
+++ hw/ppc/mac_oldworld.c
@@ -62,6 +62,11 @@
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
