--- wpa_supplicant/wpa_supplicant.c.orig	2024-07-20 18:04:37 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -7983,7 +7983,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
