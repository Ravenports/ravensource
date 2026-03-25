--- src/bele.h.orig	2026-03-05 14:57:29 UTC
+++ src/bele.h
@@ -262,12 +262,12 @@ forceinline bele_constexpr upx_uint64_t
 
 #else
 
-forceinline constexpr unsigned bswap16(unsigned v) noexcept {
+forceinline constexpr unsigned upx_bswap16(unsigned v) noexcept {
     // return __builtin_bswap32(v << 16);
     return __builtin_bswap16(upx_uint16_t(v & 0xffff));
 }
-forceinline constexpr unsigned bswap32(unsigned v) noexcept { return __builtin_bswap32(v); }
-forceinline constexpr upx_uint64_t bswap64(upx_uint64_t v) noexcept { return __builtin_bswap64(v); }
+forceinline constexpr unsigned upx_bswap32(unsigned v) noexcept { return __builtin_bswap32(v); }
+forceinline constexpr upx_uint64_t upx_bswap64(upx_uint64_t v) noexcept { return __builtin_bswap64(v); }
 
 #endif
 
@@ -282,13 +282,13 @@ forceinline constexpr upx_uint64_t no_bs
 #define ne16_to_be16(v) no_bswap16(v)
 #define ne32_to_be32(v) no_bswap32(v)
 #define ne64_to_be64(v) no_bswap64(v)
-#define ne16_to_le16(v) bswap16(v)
-#define ne32_to_le32(v) bswap32(v)
-#define ne64_to_le64(v) bswap64(v)
+#define ne16_to_le16(v) upx_bswap16(v)
+#define ne32_to_le32(v) upx_bswap32(v)
+#define ne64_to_le64(v) upx_bswap64(v)
 #elif (ACC_ABI_LITTLE_ENDIAN)
-#define ne16_to_be16(v) bswap16(v)
-#define ne32_to_be32(v) bswap32(v)
-#define ne64_to_be64(v) bswap64(v)
+#define ne16_to_be16(v) upx_bswap16(v)
+#define ne32_to_be32(v) upx_bswap32(v)
+#define ne64_to_be64(v) upx_bswap64(v)
 #define ne16_to_le16(v) no_bswap16(v)
 #define ne32_to_le32(v) no_bswap32(v)
 #define ne64_to_le64(v) no_bswap64(v)
