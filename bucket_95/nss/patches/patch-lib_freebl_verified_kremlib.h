--- lib/freebl/verified/kremlib.h.orig	2017-11-22 19:31:28.000000000 +0000
+++ lib/freebl/verified/kremlib.h	2017-12-08 19:34:46.446495189 +0000
@@ -105,6 +110,36 @@
 #define htobe32(x) OSSwapHostToBigInt32(x)
 #define be32toh(x) OSSwapBigToHostInt32(x)
 
+#elif defined(__sun__)
+#include <sys/byteorder.h>
+#define	BE_IN16(xa) htons(*((uint16_t *)(void *)(xa)))
+#define	BE_IN32(xa) htonl(*((uint32_t *)(void *)(xa)))
+#define	BE_IN64(xa) (((uint64_t)BE_IN32(xa) << 32) | BE_IN32((uint8_t *)(xa) + 4))
+
+#define	LE_IN8(xa) \
+	*((uint8_t *)(xa))
+#define	LE_IN16(xa) \
+	(((uint16_t)LE_IN8((uint8_t *)(xa) + 1) << 8) | LE_IN8(xa))
+#define	LE_IN32(xa) \
+	(((uint32_t)LE_IN16((uint8_t *)(xa) + 2) << 16) | LE_IN16(xa))
+#define	LE_IN64(xa) \
+	(((uint64_t)LE_IN32((uint8_t *)(xa) + 4) << 32) | LE_IN32(xa))
+
+#define htole64(x) LE_64(x)
+#define le64toh(x) LE_IN64(x)
+#define htobe64(x) BE_64(x)
+#define be64toh(x) BE_IN64(x)
+
+#define htole16(x) LE_16(x)
+#define le16toh(x) LE_IN16(x)
+#define htobe16(x) BE_16(x)
+#define be16toh(x) BE_IN16(x)
+
+#define htole32(x) LE_32(x)
+#define le32toh(x) LE_IN32(x)
+#define htobe32(x) BE_32(x)
+#define be32toh(x) BE_IN32(x)
+
 // ... for Windows
 #elif (defined(_WIN16) || defined(_WIN32) || defined(_WIN64)) && \
     !defined(__WINDOWS__)
