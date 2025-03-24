--- src/lib/OpenEXRCore/internal_xdr.h.orig	2025-03-22 16:08:13 UTC
+++ src/lib/OpenEXRCore/internal_xdr.h
@@ -69,6 +69,21 @@
 #    include <sys/endian.h>
 #    define EXR_HOST_IS_NOT_LITTLE_ENDIAN (__BYTE_ORDER != __LITTLE_ENDIAN)
 
+#elif defined(__sun)
+
+#  include <sys/byteorder.h>
+#  define EXR_HOST_IS_NOT_LITTLE_ENDIAN 1
+#  define LE_IN8(x)  *((uint8_t *)(x))
+#  define LE_IN16(x) (((uint16_t)LE_IN8((uint8_t *)(x) + 1) << 8) | LE_IN8(x))
+#  define LE_IN32(x) (((uint32_t)LE_IN16((uint8_t *)(x) + 2) << 16) | LE_IN16(x))
+#  define LE_IN64(x) (((uint64_t)LE_IN32((uint8_t *)(x) + 4) << 32) | LE_IN32(x))
+#  define htole16(x) LE_16(x)
+#  define le16toh(x) LE_IN16(x)
+#  define htole32(x) LE_32(x)
+#  define le32toh(x) LE_IN32(x)
+#  define htole64(x) LE_64(x)
+#  define le64toh(x) LE_IN64(x)
+
 #else
 
 #    include <endian.h>
