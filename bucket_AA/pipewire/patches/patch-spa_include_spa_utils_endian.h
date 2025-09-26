--- spa/include/spa/utils/endian.h.orig	2025-07-23 15:42:58 UTC
+++ spa/include/spa/utils/endian.h
@@ -5,7 +5,7 @@
 #ifndef SPA_ENDIAN_H
 #define SPA_ENDIAN_H
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #define bswap_16 bswap16
 #define bswap_32 bswap32
