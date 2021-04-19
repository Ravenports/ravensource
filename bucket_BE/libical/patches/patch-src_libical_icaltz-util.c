--- src/libical/icaltz-util.c.orig	2021-04-17 13:12:32 UTC
+++ src/libical/icaltz-util.c
@@ -53,6 +53,10 @@
 #define bswap_32 swap32
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define bswap_64 bswap64
+#endif
+
 #if defined(_MSC_VER)
 #if !defined(HAVE_BYTESWAP_H) && !defined(HAVE_SYS_ENDIAN_H) && !defined(HAVE_ENDIAN_H)
 #define bswap_16(x) (((x) << 8) & 0xff00) | (((x) >> 8) & 0xff)
