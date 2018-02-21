--- wpa_supplicant/wpa_supplicant.c.orig	2016-10-02 18:51:11 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -5388,7 +5388,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
