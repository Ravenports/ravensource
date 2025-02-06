--- src/filesystem/unix/SDL_sysfilesystem.c.orig	2025-02-01 23:56:51 UTC
+++ src/filesystem/unix/SDL_sysfilesystem.c
@@ -132,7 +132,7 @@ char *SDL_GetBasePath(void)
 {
     char *retval = NULL;
 
-#if defined(__FREEBSD__)
+#if defined(__FREEBSD__) && !defined(__DragonFly__)
     char fullpath[PATH_MAX];
     size_t buflen = sizeof(fullpath);
     const int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
