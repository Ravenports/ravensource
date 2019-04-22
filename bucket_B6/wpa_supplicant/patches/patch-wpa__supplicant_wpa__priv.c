--- wpa_supplicant/wpa_priv.c.orig	2019-04-21 07:10:22 UTC
+++ wpa_supplicant/wpa_priv.c
@@ -1197,6 +1197,7 @@ static void usage(void)
 int main(int argc, char *argv[])
 {
 	int c, i;
+	int eloop_initialized = 0;
 	int ret = -1;
 	char *pid_file = NULL;
 	int daemonize = 0;
@@ -1239,6 +1240,7 @@ int main(int argc, char *argv[])
 		usage();
 		goto out2;
 	}
+	else eloop_initialized = 1;
 
 	wpa_printf(MSG_DEBUG, "wpa_priv control directory: '%s'", ctrl_dir);
 
@@ -1272,7 +1274,8 @@ out:
 		wpa_priv_interface_deinit(prev);
 	}
 
-	eloop_destroy();
+	if (eloop_initialized)
+		eloop_destroy();
 
 out2:
 	if (daemonize)
