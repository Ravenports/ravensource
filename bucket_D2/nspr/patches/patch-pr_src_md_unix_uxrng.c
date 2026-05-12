--- pr/src/md/unix/uxrng.c.orig	2026-05-05 12:48:55 UTC
+++ pr/src/md/unix/uxrng.c
@@ -26,6 +26,7 @@ static size_t GetHighResClock(void* buf,
 
 #elif (defined(LINUX) || defined(FREEBSD) || defined(__FreeBSD_kernel__) || \
        defined(NETBSD) || defined(__NetBSD_kernel__) || defined(OPENBSD) || \
+       defined(__DragonFly__) || \
        defined(__GNU__))
 #  include <sys/types.h>
 #  include <sys/stat.h>
