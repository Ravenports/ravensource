--- src/lib/OpenEXRCore/internal_xdr.h.orig	2021-07-21 19:25:24 UTC
+++ src/lib/OpenEXRCore/internal_xdr.h
@@ -64,9 +64,12 @@
 #  include <sys/endian.h>
 #  define EXR_HOST_IS_NOT_LITTLE_ENDIAN (__BYTE_ORDER != __LITTLE_ENDIAN)
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__DragonFly__)
 
 #  include <sys/endian.h>
+
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
+
 #  define be16toh(x) betoh16(x)
 #  define le16toh(x) letoh16(x)
 #  define be32toh(x) betoh32(x)
