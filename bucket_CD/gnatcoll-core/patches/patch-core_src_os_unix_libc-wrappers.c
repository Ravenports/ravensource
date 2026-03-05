--- core/src/os/unix/libc-wrappers.c.orig	2025-11-28 12:36:47 UTC
+++ core/src/os/unix/libc-wrappers.c
@@ -25,6 +25,7 @@
 #define _LARGE_FILE_SOURCE 1
 #define _FILE_OFFSET_BITS 64
 #define _GNU_SOURCE 1
+#define _LARGEFILE64_SOURCE 1
 
 #include <sys/stat.h>
 #include <sys/statvfs.h>
@@ -408,6 +409,31 @@ void __gnatcoll_readdir(DIR *dirp, struc
 
   if (result != NULL)
   {
+#ifdef __DragonFly__
+     buf->inode = (uint_64) result->d_ino;
+     buf->offset = 0;
+     buf->reclen = _DIRENT_RECLEN(result->d_namlen);
+     buf->file_type = (unsigned char) result->d_type;
+     strncpy(buf->name, result->d_name, result->d_namlen);
+     buf->name[result->d_namlen] = '\0';
+
+#elif defined(__NetBSD__)
+     buf->inode = (uint_64) result->d_fileno;
+     buf->offset = 0;
+     buf->reclen = (uint_32) result->d_reclen;
+     buf->file_type = (unsigned char) result->d_type;
+     strncpy(buf->name, result->d_name, 511);
+     buf->name[511] = '\0';
+
+#elif defined(__sun__)
+     buf->inode = (uint_64) result->d_ino;
+     buf->offset = (uint_64) result->d_off;
+     buf->reclen = (uint_32) result->d_reclen;
+     buf->file_type = 0;
+     strncpy(buf->name, result->d_name, 511);
+     buf->name[511] = '\0';
+
+#else   /* All other platforms besides DragonFly and NetBSD below */
      buf->inode = (uint_64) result->d_ino;
 #if defined(__APPLE__)
      buf->offset = 0;
@@ -418,6 +444,7 @@ void __gnatcoll_readdir(DIR *dirp, struc
      buf->file_type = (unsigned char) result->d_type;
      strncpy(buf->name, result->d_name, GNATCOLL_DIRENT_NAME_MAX);
      buf->name[GNATCOLL_DIRENT_NAME_MAX - 1] = '\0';
+#endif /* ifdef __DragonFly__ || __NetBSD__ */
   } else {
      buf->inode = 0;
      buf->offset = 0;
