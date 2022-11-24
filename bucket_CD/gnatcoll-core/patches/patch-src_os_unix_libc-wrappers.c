--- src/os/unix/libc-wrappers.c.orig	2022-11-24 17:24:11 UTC
+++ src/os/unix/libc-wrappers.c
@@ -247,6 +247,14 @@ void __gnatcoll_readdir(DIR *dirp, struc
 
   if (result != NULL)
   {
+#ifdef __DragonFly__
+     buf->inode = (uint_64) result->d_ino;
+     buf->offset = 0;
+     buf->reclen = _DIRENT_RECLEN(result->d_namlen);
+     buf->file_type = (unsigned char) result->d_type;
+     strncpy(buf->name, result->d_name, result->d_namlen);
+     buf->name[result->d_namlen] = '\0';
+#else   /* All other platforms besides DragonFly below */
      buf->inode = (uint_64) result->d_ino;
 #if defined(__APPLE__)
      buf->offset = 0;
@@ -257,6 +265,7 @@ void __gnatcoll_readdir(DIR *dirp, struc
      buf->file_type = (unsigned char) result->d_type;
      strncpy(buf->name, result->d_name, GNATCOLL_DIRENT_NAME_MAX);
      buf->name[GNATCOLL_DIRENT_NAME_MAX - 1] = '\0';
+#endif /* ifdef __DragonFly__ */
   } else {
      buf->inode = 0;
      buf->offset = 0;
