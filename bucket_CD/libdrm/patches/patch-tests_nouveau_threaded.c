--- tests/nouveau/threaded.c.orig	2025-11-17 15:17:12 UTC
+++ tests/nouveau/threaded.c
@@ -36,7 +36,7 @@ static int failed;
 
 static int import_fd;
 
-#if defined(__GLIBC__) || defined(__FreeBSD__)
+#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 int ioctl(int fd, unsigned long request, ...)
 #else
 int ioctl(int fd, int request, ...)
