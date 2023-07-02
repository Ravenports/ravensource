--- src/unix/fs.c.orig	2023-06-30 18:31:51 UTC
+++ src/unix/fs.c
@@ -1098,13 +1098,13 @@ static ssize_t uv__fs_sendfile(uv_fs_t*
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
     || defined(__NetBSD__)                                                    \
@@ -1137,7 +1137,6 @@ static ssize_t uv__fs_utime(uv_fs_t* req
 static ssize_t uv__fs_lutime(uv_fs_t* req) {
 #if defined(__linux__)            ||                                           \
     defined(_AIX71)               ||                                           \
-    defined(__sun)                ||                                           \
     defined(__HAIKU__)            ||                                           \
     defined(__GNU__)              ||                                           \
     defined(__OpenBSD__)
