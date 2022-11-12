--- src/filesystem/unix/SDL_sysfilesystem.c.orig	2022-11-01 12:47:12 UTC
+++ src/filesystem/unix/SDL_sysfilesystem.c
@@ -137,7 +137,7 @@ SDL_GetBasePath(void)
 {
     char *retval = NULL;
 
-#if defined(__FREEBSD__)
+#if defined(__FREEBSD__) && !defined(__DragonFly__)
     char fullpath[PATH_MAX];
     size_t buflen = sizeof (fullpath);
     const int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
