--- Utilities/cmlibuv/src/unix/fs.c.orig	2020-04-09 12:33:17 UTC
+++ Utilities/cmlibuv/src/unix/fs.c
@@ -810,7 +810,6 @@ static ssize_t uv__fs_sendfile(uv_fs_t*
 static ssize_t uv__fs_utime(uv_fs_t* req) {
 #if defined(__linux__)                                                         \
     || defined(_AIX71)                                                         \
-    || defined(__sun)                                                          \
     || defined(__HAIKU__)
   /* utimesat() has nanosecond resolution but we stick to microseconds
    * for the sake of consistency with other platforms.
@@ -826,6 +825,7 @@ static ssize_t uv__fs_utime(uv_fs_t* req
     || defined(__FreeBSD__)                                                   \
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
+    || defined(__sun)                                                         \
     || defined(__OpenBSD__)
   struct timeval tv[2];
   tv[0].tv_sec  = req->atime;
