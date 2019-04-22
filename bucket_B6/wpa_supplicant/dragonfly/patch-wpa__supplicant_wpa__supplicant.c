--- wpa_supplicant/wpa_supplicant.c.orig	2019-04-21 07:10:22 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -6357,7 +6357,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
