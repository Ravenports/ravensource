--- src/dlmisc.c.orig	2020-10-19 09:45:13 UTC
+++ src/dlmisc.c
@@ -42,11 +42,9 @@
 #ifndef PIC
 struct snd_dlsym_link *snd_dlsym_start = NULL;
 #endif
-#ifdef DL_ORIGIN_AVAILABLE
 static int snd_plugin_dir_set = 0;
 static char *snd_plugin_dir = NULL;
 #endif
-#endif
 
 #if defined(DL_ORIGIN_AVAILABLE) && defined(HAVE_LIBPTHREAD)
 static pthread_mutex_t snd_dlpath_mutex = PTHREAD_MUTEX_INITIALIZER;
