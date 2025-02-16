--- include/SDL_endian.h.orig	2025-02-08 17:10:22 UTC
+++ include/SDL_endian.h
@@ -68,10 +68,10 @@ _m_prefetch(void *__P)
 #else
 #error Unsupported endianness
 #endif
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__OpenBSD__)
 #include <endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
 /* predefs from newer gcc and clang versions: */
