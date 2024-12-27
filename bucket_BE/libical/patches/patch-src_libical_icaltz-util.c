--- src/libical/icaltz-util.c.orig	2024-12-23 12:01:49 UTC
+++ src/libical/icaltz-util.c
@@ -53,6 +53,11 @@
 #define bswap_32 swap32
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#define bswap_64 bswap64
+#define bswap_32 bswap32
+#endif
+
 #if defined(_MSC_VER)
 #if !defined(HAVE_BYTESWAP_H) && !defined(HAVE_SYS_ENDIAN_H) && !defined(HAVE_ENDIAN_H)
 #define bswap_16(x) (((x) << 8) & 0xff00) | (((x) >> 8) & 0xff)
