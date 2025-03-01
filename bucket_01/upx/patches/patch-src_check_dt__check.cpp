--- src/check/dt_check.cpp.orig	2025-02-20 15:02:44 UTC
+++ src/check/dt_check.cpp
@@ -288,12 +288,12 @@ static_assert(no_bswap16(0x04030201) ==
 static_assert(no_bswap32(0x04030201) == 0x04030201);
 static_assert(no_bswap64(0x0807060504030201ull) == 0x0807060504030201ull);
 #if !(ACC_CC_MSC) || defined(upx_is_constant_evaluated)
-static_assert(bswap16(0x04030201) == 0x0102);
-static_assert(bswap32(0x04030201) == 0x01020304);
-static_assert(bswap64(0x0807060504030201ull) == 0x0102030405060708ull);
-static_assert(bswap16(bswap16(0xf4f3f2f1)) == no_bswap16(0xf4f3f2f1));
-static_assert(bswap32(bswap32(0xf4f3f2f1)) == no_bswap32(0xf4f3f2f1));
-static_assert(bswap64(bswap64(0xf8f7f6f5f4f3f2f1ull)) == no_bswap64(0xf8f7f6f5f4f3f2f1ull));
+static_assert(upx_bswap16(0x04030201) == 0x0102);
+static_assert(upx_bswap32(0x04030201) == 0x01020304);
+static_assert(upx_bswap64(0x0807060504030201ull) == 0x0102030405060708ull);
+static_assert(upx_bswap16(bswap16(0xf4f3f2f1)) == no_bswap16(0xf4f3f2f1));
+static_assert(upx_bswap32(bswap32(0xf4f3f2f1)) == no_bswap32(0xf4f3f2f1));
+static_assert(upx_bswap64(bswap64(0xf8f7f6f5f4f3f2f1ull)) == no_bswap64(0xf8f7f6f5f4f3f2f1ull));
 #endif
 
 static_assert(sign_extend(0u + 0, 8) == 0);
