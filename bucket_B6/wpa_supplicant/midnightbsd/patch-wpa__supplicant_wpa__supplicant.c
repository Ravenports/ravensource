--- wpa_supplicant/wpa_supplicant.c.orig	2022-01-16 20:51:29 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -7311,7 +7311,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
