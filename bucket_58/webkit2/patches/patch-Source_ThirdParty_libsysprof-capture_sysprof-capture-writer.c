--- Source/ThirdParty/libsysprof-capture/sysprof-capture-writer.c.orig	2026-01-20 14:08:34 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-capture-writer.c
@@ -59,6 +59,7 @@
 #include <assert.h>
 #ifdef __APPLE__
 # include <machine/endian.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #else
 # include <endian.h>
 #endif
