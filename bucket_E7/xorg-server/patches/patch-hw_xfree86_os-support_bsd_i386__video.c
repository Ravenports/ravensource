--- hw/xfree86/os-support/bsd/i386_video.c.orig	2024-10-29 16:09:01 UTC
+++ hw/xfree86/os-support/bsd/i386_video.c
@@ -32,6 +32,7 @@
 #include "xf86Priv.h"
 
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 
 #include "xf86_OSlib.h"
@@ -42,6 +43,9 @@
 #else
 #define MAP_FLAGS (MAP_FILE | MAP_SHARED)
 #endif
+#if defined(__NetBSD__) && defined(USE_AMD64_IOPL)
+#define amd64_iopl x86_64_iopl
+#endif
 
 #ifdef __OpenBSD__
 #define SYSCTL_MSG "\tCheck that you have set 'machdep.allowaperture=1'\n"\
