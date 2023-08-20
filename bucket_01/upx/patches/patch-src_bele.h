--- src/bele.h.orig	2023-08-08 08:38:12 UTC
+++ src/bele.h
@@ -37,9 +37,6 @@
 #undef bswap16
 #undef bswap32
 #undef bswap64
-#define bswap16 upx_bswap16
-#define bswap32 upx_bswap32
-#define bswap64 upx_bswap64
 #endif
 
 /*************************************************************************
