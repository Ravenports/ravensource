--- src/local-endian.h.orig	2026-05-10 17:55:13 UTC
+++ src/local-endian.h
@@ -31,6 +31,8 @@
 #ifndef LIBMD_LOCAL_ENDIAN_H
 #define LIBMD_LOCAL_ENDIAN_H
 
+#if !defined(__NetBSD__)
+
 #include <stdint.h>
 
 #define __inline inline
@@ -143,4 +145,6 @@ le64enc(void *pp, uint64_t u)
 	le32enc(p + 4, (uint32_t)(u >> 32));
 }
 
+#endif // __NetBSD__
+
 #endif
