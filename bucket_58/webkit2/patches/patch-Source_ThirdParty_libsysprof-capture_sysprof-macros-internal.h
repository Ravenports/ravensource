--- Source/ThirdParty/libsysprof-capture/sysprof-macros-internal.h.orig	2024-08-19 06:28:36 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-macros-internal.h
@@ -64,6 +64,8 @@
 #ifdef __APPLE__
 # include <libkern/OSByteOrder.h>
 # include <architecture/byte_order.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+# include <sys/endian.h>
 #else
 # include <byteswap.h>
 # include <endian.h>
