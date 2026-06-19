--- src/util/os_drm.h.orig	2026-05-14 07:49:34 UTC
+++ src/util/os_drm.h
@@ -14,6 +14,7 @@
 #error "Windows shouldn't include this."
 #endif
 
+#include <unistd.h>  // for ioctl on sunos
 #include <sys/ioctl.h>
 #include <errno.h>
 #include <xf86drm.h>
