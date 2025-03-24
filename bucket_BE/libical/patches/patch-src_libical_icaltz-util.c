--- src/libical/icaltz-util.c.orig	2025-03-10 16:08:27 UTC
+++ src/libical/icaltz-util.c
@@ -43,6 +43,11 @@
 #endif
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#define bswap_64 bswap64
+#define bswap_32 bswap32
+#endif
+
 #if defined(_MSC_VER)
 #if !defined(HAVE_BYTESWAP_H) && !defined(HAVE_SYS_ENDIAN_H) && !defined(HAVE_ENDIAN_H)
 #define bswap_16(x) (((x) << 8) & 0xff00) | (((x) >> 8) & 0xff)
