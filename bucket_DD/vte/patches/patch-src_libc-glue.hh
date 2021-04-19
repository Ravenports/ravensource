--- src/libc-glue.hh.orig	2021-04-16 17:22:42 UTC
+++ src/libc-glue.hh
@@ -220,7 +220,13 @@ fd_dup_cloexec(int oldfd,
 {
         auto r = int{};
         do {
+#ifdef F_DUPFD_CLOEXEC
                 r = fcntl(oldfd, F_DUPFD_CLOEXEC, newfd);
+#else
+                r = fcntl(oldfd, F_DUPFD, 0);
+                newfd = r;
+                fcntl(newfd, F_SETFD, FD_CLOEXEC);
+#endif
         } while (r == -1 && errno == EINTR);
         return r;
 }
