--- src/scandir.c.orig	2018-08-07 06:43:51 UTC
+++ src/scandir.c
@@ -40,6 +40,8 @@ int ag_scandir(const char *dirname,
 
 #if defined(__MINGW32__) || defined(__CYGWIN__)
         d = malloc(sizeof(struct dirent));
+#elif defined(__DragonFly__)
+	d = malloc(_DIRENT_RECLEN(entry->d_namlen));
 #else
         d = malloc(entry->d_reclen);
 #endif
@@ -49,6 +51,8 @@ int ag_scandir(const char *dirname,
         }
 #if defined(__MINGW32__) || defined(__CYGWIN__)
         memcpy(d, entry, sizeof(struct dirent));
+#elif defined (__DragonFly__)
+	memcpy(d, entry, _DIRENT_RECLEN(entry->d_namlen));
 #else
         memcpy(d, entry, entry->d_reclen);
 #endif
