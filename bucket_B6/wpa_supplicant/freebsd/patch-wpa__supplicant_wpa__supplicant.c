--- wpa_supplicant/wpa_supplicant.c.orig	2019-08-07 13:25:25 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -6367,7 +6367,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
