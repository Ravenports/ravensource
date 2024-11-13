--- pr/src/md/unix/uxrng.c.orig	2024-10-21 11:31:57 UTC
+++ pr/src/md/unix/uxrng.c
@@ -52,6 +52,7 @@ static size_t GetHighResClock(void* buf,
 
 #elif (defined(LINUX) || defined(FREEBSD) || defined(__FreeBSD_kernel__) || \
        defined(NETBSD) || defined(__NetBSD_kernel__) || defined(OPENBSD) || \
+       defined(__DragonFly__) || \
        defined(__GNU__))
 #  include <sys/types.h>
 #  include <sys/stat.h>
