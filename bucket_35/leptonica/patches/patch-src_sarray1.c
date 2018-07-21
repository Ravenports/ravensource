--- src/sarray1.c.orig	2018-04-13 21:35:39 UTC
+++ src/sarray1.c
@@ -1882,7 +1882,11 @@ struct stat     st;
         return (SARRAY *)ERROR_PTR("pdir not opened", procName, NULL);
     }
     safiles = sarrayCreate(0);
+#ifdef __sun__
+    dfd = pdir->dd_fd;
+#else
     dfd = dirfd(pdir);
+#endif
     while ((pdirentry = readdir(pdir))) {
 #if HAVE_FSTATAT
         stat_ret = fstatat(dfd, pdirentry->d_name, &st, 0);
