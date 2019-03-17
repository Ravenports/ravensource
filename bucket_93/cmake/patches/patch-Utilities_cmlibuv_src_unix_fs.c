--- Utilities/cmlibuv/src/unix/fs.c.orig	2019-03-14 13:15:56 UTC
+++ Utilities/cmlibuv/src/unix/fs.c
@@ -702,7 +702,6 @@ static ssize_t uv__fs_sendfile(uv_fs_t*
 static ssize_t uv__fs_utime(uv_fs_t* req) {
 #if defined(__linux__)                                                         \
     || defined(_AIX71)                                                         \
-    || defined(__sun)
   /* utimesat() has nanosecond resolution but we stick to microseconds
    * for the sake of consistency with other platforms.
    */
@@ -718,6 +717,7 @@ static ssize_t uv__fs_utime(uv_fs_t* req
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
     || defined(__OpenBSD__)
+    || defined(__sun)
   struct timeval tv[2];
   tv[0].tv_sec  = req->atime;
   tv[0].tv_usec = (uint64_t)(req->atime * 1000000) % 1000000;
