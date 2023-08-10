--- src/bele.h.orig	2023-01-30 10:18:06 UTC
+++ src/bele.h
@@ -85,6 +85,7 @@ static forceinline unsigned bswap32(unsi
 static forceinline upx_uint64_t bswap64(upx_uint64_t v) { return _byteswap_uint64(v); }
 
 #else
+# if defined(__FreeBSD__) || defined(__DragonFly__)
 
 static forceinline constexpr unsigned bswap16(unsigned v) {
     // return __builtin_bswap16((upx_uint16_t) (v & 0xffff));
@@ -97,6 +98,7 @@ static forceinline constexpr unsigned bs
 }
 static forceinline constexpr upx_uint64_t bswap64(upx_uint64_t v) { return __builtin_bswap64(v); }
 
+# endif
 #endif
 
 static forceinline constexpr unsigned no_bswap16(unsigned v) {
