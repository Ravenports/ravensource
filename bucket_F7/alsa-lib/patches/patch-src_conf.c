--- src/conf.c.orig	2021-06-14 10:28:44 UTC
+++ src/conf.c
@@ -4059,7 +4059,7 @@ static int config_file_load(snd_config_t
 	if (!S_ISDIR(st.st_mode))
 		return config_file_open(root, fn);
 #ifndef DOC_HIDDEN
-#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun) && !defined(ANDROID)
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun) && !defined(ANDROID) &&!defined(__DragonFly__)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
