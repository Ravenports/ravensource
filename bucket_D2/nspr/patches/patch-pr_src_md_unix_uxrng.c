--- pr/src/md/unix/uxrng.c.orig	2026-08-05 04:57:49 UTC
+++ pr/src/md/unix/uxrng.c
@@ -32,6 +32,7 @@ GetHighResClock(void* buf, size_t maxbyt
 
 #elif (defined(LINUX) || defined(FREEBSD) || defined(__FreeBSD_kernel__) || \
        defined(NETBSD) || defined(__NetBSD_kernel__) || defined(OPENBSD) || \
+       defined(__DragonFly__) || \
        defined(__GNU__))
 #include <sys/types.h>
 #include <sys/stat.h>
