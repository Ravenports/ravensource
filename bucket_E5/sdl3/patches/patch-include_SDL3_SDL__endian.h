--- include/SDL3/SDL_endian.h.orig	2025-07-14 17:02:46 UTC
+++ include/SDL3/SDL_endian.h
@@ -140,10 +140,10 @@ _m_prefetch(void *__P)
 #else
 #error Unsupported endianness
 #endif
-#elif defined(SDL_PLATFORM_OPENBSD) || defined(__DragonFly__)
+#elif defined(SDL_PLATFORM_OPENBSD)
 #include <endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
-#elif defined(SDL_PLATFORM_FREEBSD) || defined(SDL_PLATFORM_NETBSD)
+#elif defined(SDL_PLATFORM_FREEBSD) || defined(SDL_PLATFORM_NETBSD) || defined(__DragonFly__)
 #include <sys/endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
 /* predefs from newer gcc and clang versions: */
