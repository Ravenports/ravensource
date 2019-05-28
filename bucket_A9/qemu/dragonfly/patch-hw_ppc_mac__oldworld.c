--- hw/ppc/mac_oldworld.c.orig	2018-12-11 17:44:34 UTC
+++ hw/ppc/mac_oldworld.c
@@ -59,6 +59,11 @@
 
 #define GRACKLE_BASE 0xfec00000
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static void fw_cfg_boot_set(void *opaque, const char *boot_device,
                             Error **errp)
 {
