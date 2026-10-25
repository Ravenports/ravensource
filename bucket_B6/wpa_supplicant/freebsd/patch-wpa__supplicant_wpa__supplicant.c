--- wpa_supplicant/wpa_supplicant.c.orig	2026-08-07 13:10:53 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -8723,13 +8723,6 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
-	{
-		void driver_ndis_init_ops(void);
-		driver_ndis_init_ops();
-	}
-#endif /* CONFIG_DRIVER_NDIS */
-
 #ifndef CONFIG_NO_WPA_MSG
 	wpa_msg_register_ifname_cb(wpa_supplicant_msg_ifname_cb);
 #endif /* CONFIG_NO_WPA_MSG */
