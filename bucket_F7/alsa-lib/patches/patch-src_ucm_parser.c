--- src/ucm/parser.c.orig	2021-12-09 13:17:59 UTC
+++ src/ucm/parser.c
@@ -2479,7 +2479,7 @@ int uc_mgr_scan_master_configs(const cha
 		snprintf(filename, sizeof(filename), "%s/ucm2/conf.virt.d",
 			 snd_config_topdir());
 
-#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun) && !defined(ANDROID)
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun) && !defined(ANDROID) && !defined(__DragonFly__)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
