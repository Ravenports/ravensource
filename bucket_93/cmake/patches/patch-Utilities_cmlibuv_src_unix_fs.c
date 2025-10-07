--- Utilities/cmlibuv/src/unix/fs.c.orig	2025-09-30 14:48:33 UTC
+++ Utilities/cmlibuv/src/unix/fs.c
@@ -1167,7 +1167,6 @@ static ssize_t uv__fs_sendfile(uv_fs_t*
 static ssize_t uv__fs_utime(uv_fs_t* req) {
 #if defined(__linux__)                                                         \
     || defined(_AIX71)                                                         \
-    || defined(__sun)                                                          \
     || defined(__HAIKU__)
   struct timespec ts[2];
   ts[0] = uv__fs_to_timespec(req->atime);
@@ -1178,6 +1177,7 @@ static ssize_t uv__fs_utime(uv_fs_t* req
     || defined(__FreeBSD__)                                                   \
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
+    || defined(__sun)                                                         \
     || defined(__OpenBSD__)
   struct timeval tv[2];
   tv[0] = uv__fs_to_timeval(req->atime);
@@ -1207,7 +1207,6 @@ static ssize_t uv__fs_utime(uv_fs_t* req
 static ssize_t uv__fs_lutime(uv_fs_t* req) {
 #if defined(__linux__)            ||                                           \
     defined(_AIX71)               ||                                           \
-    defined(__sun)                ||                                           \
     defined(__HAIKU__)            ||                                           \
     defined(__GNU__)              ||                                           \
     defined(__OpenBSD__)
