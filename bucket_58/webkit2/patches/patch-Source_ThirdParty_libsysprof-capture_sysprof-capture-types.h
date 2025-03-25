--- Source/ThirdParty/libsysprof-capture/sysprof-capture-types.h.orig	2025-02-25 08:25:38 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-capture-types.h
@@ -59,6 +59,8 @@
 #include <assert.h>
 #ifdef __APPLE__
 # include <machine/endian.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
+# include <sys/endian.h>
 #else
 # include <endian.h>
 #endif
