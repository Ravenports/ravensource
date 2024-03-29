--- util.h.orig	2007-12-27 00:51:05 UTC
+++ util.h
@@ -19,7 +19,7 @@
 #  include <config.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/endian.h>
 
 #define __BYTE_ORDER            _BYTE_ORDER
@@ -29,6 +29,33 @@
 #define bswap_16                bswap16
 #define bswap_32                bswap32
 #define bswap_64                bswap64
+#elif defined(__APPLE__)
+#include <machine/endian.h>
+#include <libkern/OSByteOrder.h>
+
+#define __BYTE_ORDER            BYTE_ORDER
+#define __LITTLE_ENDIAN         LITTLE_ENDIAN
+#define __BIG_ENDIAN            BIG_ENDIAN
+
+#define bswap_16                OSSwapInt16
+#define bswap_32                OSSwapInt32
+#define bswap_64                OSSwapInt64
+#elif defined(__sun__)
+#include <sys/isa_defs.h>
+#include <sys/byteorder.h>
+
+#define __LITTLE_ENDIAN		1234
+#define __BIG_ENDIAN		4321
+#if defined(_BIG_ENDIAN)
+#define	__BYTE_ORDER		__BIG_ENDIAN
+#elif defined(_LITTLE_ENDIAN)
+#define __BYTE_ORDER		__LITTLE_ENDIAN
+#endif
+
+#define bswap_16		BSWAP_16
+#define bswap_32		BSWAP_32
+#define bswap_64		BSWAP_64
+
 #else
 #include <endian.h>
 #include <byteswap.h>
