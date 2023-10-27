--- src/libuv/src/unix/fs.c.orig	2023-10-23 16:48:26 UTC
+++ src/libuv/src/unix/fs.c
@@ -1127,13 +1127,13 @@ static ssize_t uv__fs_sendfile(uv_fs_t*
 static ssize_t uv__fs_utime(uv_fs_t* req) {
 #if defined(__linux__)                                                         \
     || defined(_AIX71)                                                         \
-    || defined(__sun)                                                          \
     || defined(__HAIKU__)
   struct timespec ts[2];
   ts[0] = uv__fs_to_timespec(req->atime);
   ts[1] = uv__fs_to_timespec(req->mtime);
   return utimensat(AT_FDCWD, req->path, ts, 0);
 #elif defined(__APPLE__)                                                      \
+    || defined(__sun)                                                         \
     || defined(__DragonFly__)                                                 \
     || defined(__FreeBSD__)                                                   \
     || defined(__FreeBSD_kernel__)                                            \
@@ -1167,7 +1167,6 @@ static ssize_t uv__fs_utime(uv_fs_t* req
 static ssize_t uv__fs_lutime(uv_fs_t* req) {
 #if defined(__linux__)            ||                                           \
     defined(_AIX71)               ||                                           \
-    defined(__sun)                ||                                           \
     defined(__HAIKU__)
   struct timespec ts[2];
   ts[0] = uv__fs_to_timespec(req->atime);
