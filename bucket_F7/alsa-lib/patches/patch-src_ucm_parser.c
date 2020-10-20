--- src/ucm/parser.c.orig	2020-10-19 09:45:13 UTC
+++ src/ucm/parser.c
@@ -2299,7 +2299,7 @@ int uc_mgr_scan_master_configs(const cha
 		snprintf(filename, sizeof(filename), "%s/ucm2",
 			 snd_config_topdir());
 
-#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun) && !defined(ANDROID)
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun) && !defined(ANDROID) && !defined(__DragonFly__)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
