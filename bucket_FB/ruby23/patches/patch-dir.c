--- dir.c.orig	2018-03-28 10:24:57 UTC
+++ dir.c
@@ -93,16 +93,16 @@ char *strchr(char*,char);
 # define USE_NAME_ON_FS 0
 #endif
 
-#ifdef __APPLE__
+#if 0
 # define NORMALIZE_UTF8PATH 1
 #else
 # define NORMALIZE_UTF8PATH 0
 #endif
 
+#include <sys/vnode.h>
 #if NORMALIZE_UTF8PATH
 #include <sys/param.h>
 #include <sys/mount.h>
-#include <sys/vnode.h>
 
 # if defined HAVE_FGETATTRLIST || !defined HAVE_GETATTRLIST
 #   define need_normalization(dirp, path) need_normalization(dirp)
@@ -1017,7 +1017,7 @@ rb_dir_getwd(void)
 
     if (fsenc == ENCINDEX_US_ASCII) fsenc = ENCINDEX_ASCII;
     path = my_getcwd();
-#ifdef __APPLE__
+#if NORMALIZE_UTF8PATH
     cwd = rb_str_normalize_ospath(path, strlen(path));
     OBJ_TAINT(cwd);
 #else
