--- Utilities/cmlibuv/src/unix/fs.c.orig	2021-02-24 15:08:43 UTC
+++ Utilities/cmlibuv/src/unix/fs.c
@@ -1018,7 +1018,6 @@ ok:
 static ssize_t uv__fs_utime(uv_fs_t* req) {
 #if defined(__linux__)                                                         \
     || defined(_AIX71)                                                         \
-    || defined(__sun)                                                          \
     || defined(__HAIKU__)
   /* utimesat() has nanosecond resolution but we stick to microseconds
    * for the sake of consistency with other platforms.
@@ -1032,6 +1031,7 @@ static ssize_t uv__fs_utime(uv_fs_t* req
     || defined(__FreeBSD__)                                                   \
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
+    || defined(__sun)                                                         \
     || defined(__OpenBSD__)
   struct timeval tv[2];
   tv[0] = uv__fs_to_timeval(req->atime);
@@ -1061,7 +1061,6 @@ static ssize_t uv__fs_utime(uv_fs_t* req
 static ssize_t uv__fs_lutime(uv_fs_t* req) {
 #if defined(__linux__)            ||                                           \
     defined(_AIX71)               ||                                           \
-    defined(__sun)                ||                                           \
     defined(__HAIKU__)
   struct timespec ts[2];
   ts[0] = uv__fs_to_timespec(req->atime);
