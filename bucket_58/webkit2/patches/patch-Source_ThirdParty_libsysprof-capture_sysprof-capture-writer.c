--- Source/ThirdParty/libsysprof-capture/sysprof-capture-writer.c.orig	2024-09-30 08:15:01 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-capture-writer.c
@@ -59,6 +59,7 @@
 #include <assert.h>
 #ifdef __APPLE__
 # include <machine/endian.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
 #else
 # include <endian.h>
 #endif
