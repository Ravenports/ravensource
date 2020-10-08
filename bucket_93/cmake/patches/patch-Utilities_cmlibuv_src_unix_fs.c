--- Utilities/cmlibuv/src/unix/fs.c.orig	2020-10-06 12:28:17 UTC
+++ Utilities/cmlibuv/src/unix/fs.c
@@ -986,7 +986,6 @@ static ssize_t uv__fs_sendfile(uv_fs_t*
 static ssize_t uv__fs_utime(uv_fs_t* req) {
 #if defined(__linux__)                                                         \
     || defined(_AIX71)                                                         \
-    || defined(__sun)                                                          \
     || defined(__HAIKU__)
   /* utimesat() has nanosecond resolution but we stick to microseconds
    * for the sake of consistency with other platforms.
@@ -1000,6 +999,7 @@ static ssize_t uv__fs_utime(uv_fs_t* req
     || defined(__FreeBSD__)                                                   \
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
+    || defined(__sun)                                                         \
     || defined(__OpenBSD__)
   struct timeval tv[2];
   tv[0] = uv__fs_to_timeval(req->atime);
