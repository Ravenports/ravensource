--- src/bele.h.orig	2024-05-09 10:03:12 UTC
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
@@ -169,7 +166,7 @@ static forceinline /*constexpr*/ upx_uin
 
 #else
 
-static forceinline constexpr unsigned bswap16(unsigned v) noexcept {
+static forceinline constexpr unsigned upx_bswap16(unsigned v) noexcept {
 #if defined(__riscv) && __riscv_xlen == 64
     return (unsigned) __builtin_bswap64((upx_uint64_t) v << 48);
 #else
@@ -177,14 +174,14 @@ static forceinline constexpr unsigned bs
     return __builtin_bswap32(v << 16);
 #endif
 }
-static forceinline constexpr unsigned bswap32(unsigned v) noexcept {
+static forceinline constexpr unsigned upx_bswap32(unsigned v) noexcept {
 #if defined(__riscv) && __riscv_xlen == 64
     return (unsigned) __builtin_bswap64((upx_uint64_t) v << 32);
 #else
     return __builtin_bswap32(v);
 #endif
 }
-static forceinline constexpr upx_uint64_t bswap64(upx_uint64_t v) noexcept {
+static forceinline constexpr upx_uint64_t upx_bswap64(upx_uint64_t v) noexcept {
     return __builtin_bswap64(v);
 }
 
@@ -201,13 +198,13 @@ static forceinline constexpr upx_uint64_
 #define ne16_to_be16(v) no_bswap16(v)
 #define ne32_to_be32(v) no_bswap32(v)
 #define ne64_to_be64(v) no_bswap64(v)
-#define ne16_to_le16(v) bswap16(v)
-#define ne32_to_le32(v) bswap32(v)
-#define ne64_to_le64(v) bswap64(v)
+#define ne16_to_le16(v) upx_bswap16(v)
+#define ne32_to_le32(v) upx_bswap32(v)
+#define ne64_to_le64(v) upx_bswap64(v)
 #else
-#define ne16_to_be16(v) bswap16(v)
-#define ne32_to_be32(v) bswap32(v)
-#define ne64_to_be64(v) bswap64(v)
+#define ne16_to_be16(v) upx_bswap16(v)
+#define ne32_to_be32(v) upx_bswap32(v)
+#define ne64_to_be64(v) upx_bswap64(v)
 #define ne16_to_le16(v) no_bswap16(v)
 #define ne32_to_le32(v) no_bswap32(v)
 #define ne64_to_le64(v) no_bswap64(v)
