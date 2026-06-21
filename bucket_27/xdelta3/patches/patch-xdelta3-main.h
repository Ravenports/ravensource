--- xdelta3-main.h.orig	2026-06-21 04:37:32 UTC
+++ xdelta3-main.h
@@ -126,7 +126,9 @@ int xsnprintf_func(char *str, size_t n,
 #if defined(__linux__)
 #include <sys/ioctl.h>
 #include <linux/fs.h> /* BLKGETSIZE64 */
-#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) ||  \
+#elif defined(__DragonFly__)
+#include <sys/ioctl.h>
+#elif defined(__APPLE__) || defined(__FreeBSD__) || \
     defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/ioctl.h>
 #include <sys/disk.h> /* DKIOCGETBLOCK*, DIOCGMEDIASIZE */
