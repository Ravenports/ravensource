--- src/bele.h.orig	2023-08-08 08:38:12 UTC
+++ src/bele.h
@@ -95,6 +95,7 @@ static forceinline unsigned bswap32(unsi
 static forceinline upx_uint64_t bswap64(upx_uint64_t v) noexcept { return _byteswap_uint64(v); }
 
 #else
+# if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 
 static forceinline constexpr unsigned bswap16(unsigned v) noexcept {
     // return __builtin_bswap16((upx_uint16_t) (v & 0xffff));
@@ -109,6 +110,7 @@ static forceinline constexpr upx_uint64_
     return __builtin_bswap64(v);
 }
 
+# endif
 #endif
 
 static forceinline constexpr unsigned no_bswap16(unsigned v) noexcept {
