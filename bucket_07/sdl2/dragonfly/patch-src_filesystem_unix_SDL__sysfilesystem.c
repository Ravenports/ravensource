--- src/filesystem/unix/SDL_sysfilesystem.c.orig	2020-12-21 17:44:36 UTC
+++ src/filesystem/unix/SDL_sysfilesystem.c
@@ -83,7 +83,7 @@ SDL_GetBasePath(void)
 {
     char *retval = NULL;
 
-#if defined(__FREEBSD__)
+#if defined(__FREEBSD__) && !defined(__DragonFly__)
     char fullpath[PATH_MAX];
     size_t buflen = sizeof (fullpath);
     const int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
