--- wpa_supplicant/main.c.orig	2026-08-07 13:10:53 UTC
+++ wpa_supplicant/main.c
@@ -70,7 +70,7 @@ static void usage(void)
 	       "  -c = Configuration file\n"
 	       "  -C = ctrl_interface parameter (only used if -c is not)\n"
 	       "  -d = increase debugging verbosity (-dd even more)\n"
-	       "  -D = driver name (can be multiple drivers: nl80211,wext)\n"
+	       "  -D = driver name (can be multiple drivers: bsd,wired)\n"
 	       "  -e = entropy file\n"
 #ifdef CONFIG_DEBUG_FILE
 	       "  -f = log output to debug file instead of stdout\n"
@@ -211,6 +211,11 @@ int main(int argc, char *argv[])
 
 	wpa_supplicant_fd_workaround(1);
 
+#ifdef CONFIG_DRIVER_NDIS
+	void driver_ndis_init_ops(void);
+	driver_ndis_init_ops();
+#endif /* CONFIG_DRIVER_NDIS */
+
 	for (;;) {
 		c = getopt(argc, argv,
 			   "b:Bc:C:D:de:f:g:G:hi:I:KLMm:No:O:p:P:qsTtuvWyz:");
