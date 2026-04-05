--- wpa_supplicant/wpa_priv.c.orig	2024-07-20 18:04:37 UTC
+++ wpa_supplicant/wpa_priv.c
@@ -1210,6 +1210,7 @@ static void usage(void)
 int main(int argc, char *argv[])
 {
 	int c, i;
+	int eloop_initialized = 0;
 	int ret = -1;
 	char *pid_file = NULL;
 	int daemonize = 0;
@@ -1252,6 +1253,7 @@ int main(int argc, char *argv[])
 		usage();
 		goto out2;
 	}
+	else eloop_initialized = 1;
 
 	wpa_printf(MSG_DEBUG, "wpa_priv control directory: '%s'", ctrl_dir);
 
@@ -1285,7 +1287,8 @@ out:
 		wpa_priv_interface_deinit(prev);
 	}
 
-	eloop_destroy();
+	if (eloop_initialized)
+		eloop_destroy();
 
 out2:
 	if (daemonize)
