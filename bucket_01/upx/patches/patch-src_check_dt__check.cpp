--- src/check/dt_check.cpp.orig	2024-05-09 10:03:12 UTC
+++ src/check/dt_check.cpp
@@ -108,12 +108,12 @@ ACC_COMPILE_TIME_ASSERT_HEADER(no_bswap1
 ACC_COMPILE_TIME_ASSERT_HEADER(no_bswap32(0x04030201) == 0x04030201)
 ACC_COMPILE_TIME_ASSERT_HEADER(no_bswap64(0x0807060504030201ull) == 0x0807060504030201ull)
 #if !(ACC_CC_MSC) // unfortunately *not* constexpr with current MSVC
-ACC_COMPILE_TIME_ASSERT_HEADER(bswap16(0x04030201) == 0x0102)
-ACC_COMPILE_TIME_ASSERT_HEADER(bswap32(0x04030201) == 0x01020304)
-ACC_COMPILE_TIME_ASSERT_HEADER(bswap64(0x0807060504030201ull) == 0x0102030405060708ull)
-ACC_COMPILE_TIME_ASSERT_HEADER(bswap16(bswap16(0xf4f3f2f1)) == no_bswap16(0xf4f3f2f1))
-ACC_COMPILE_TIME_ASSERT_HEADER(bswap32(bswap32(0xf4f3f2f1)) == no_bswap32(0xf4f3f2f1))
-ACC_COMPILE_TIME_ASSERT_HEADER(bswap64(bswap64(0xf8f7f6f5f4f3f2f1ull)) ==
+ACC_COMPILE_TIME_ASSERT_HEADER(upx_bswap16(0x04030201) == 0x0102)
+ACC_COMPILE_TIME_ASSERT_HEADER(upx_bswap32(0x04030201) == 0x01020304)
+ACC_COMPILE_TIME_ASSERT_HEADER(upx_bswap64(0x0807060504030201ull) == 0x0102030405060708ull)
+ACC_COMPILE_TIME_ASSERT_HEADER(upx_bswap16(upx_bswap16(0xf4f3f2f1)) == no_bswap16(0xf4f3f2f1))
+ACC_COMPILE_TIME_ASSERT_HEADER(upx_bswap32(upx_bswap32(0xf4f3f2f1)) == no_bswap32(0xf4f3f2f1))
+ACC_COMPILE_TIME_ASSERT_HEADER(upx_bswap64(upx_bswap64(0xf8f7f6f5f4f3f2f1ull)) ==
                                no_bswap64(0xf8f7f6f5f4f3f2f1ull))
 #endif
 
