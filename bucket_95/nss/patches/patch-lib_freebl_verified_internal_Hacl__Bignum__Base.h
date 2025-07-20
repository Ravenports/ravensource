--- lib/freebl/verified/internal/Hacl_Bignum_Base.h.orig	2025-07-17 20:31:27 UTC
+++ lib/freebl/verified/internal/Hacl_Bignum_Base.h
@@ -67,7 +67,7 @@ Hacl_Bignum_Convert_bn_from_bytes_be_uin
     uint32_t bnLen = (len - (uint32_t)1U) / (uint32_t)8U + (uint32_t)1U;
     uint32_t tmpLen = (uint32_t)8U * bnLen;
     KRML_CHECK_SIZE(sizeof(uint8_t), tmpLen);
-    uint8_t *tmp = (uint8_t *)alloca(tmpLen * sizeof(uint8_t));
+    uint8_t *tmp = (uint8_t *)__builtin_alloca(tmpLen * sizeof(uint8_t));
     memset(tmp, 0U, tmpLen * sizeof(uint8_t));
     memcpy(tmp + tmpLen - len, b, len * sizeof(uint8_t));
     for (uint32_t i = (uint32_t)0U; i < bnLen; i++) {
@@ -84,7 +84,7 @@ Hacl_Bignum_Convert_bn_to_bytes_be_uint6
     uint32_t bnLen = (len - (uint32_t)1U) / (uint32_t)8U + (uint32_t)1U;
     uint32_t tmpLen = (uint32_t)8U * bnLen;
     KRML_CHECK_SIZE(sizeof(uint8_t), tmpLen);
-    uint8_t *tmp = (uint8_t *)alloca(tmpLen * sizeof(uint8_t));
+    uint8_t *tmp = (uint8_t *)__builtin_alloca(tmpLen * sizeof(uint8_t));
     memset(tmp, 0U, tmpLen * sizeof(uint8_t));
     for (uint32_t i = (uint32_t)0U; i < bnLen; i++) {
         store64_be(tmp + i * (uint32_t)8U, b[bnLen - i - (uint32_t)1U]);
@@ -376,7 +376,7 @@ Hacl_Bignum_Multiplication_bn_sqr_u32(ui
     uint32_t c0 = Hacl_Bignum_Addition_bn_add_eq_len_u32(aLen + aLen, res, res, res);
     KRML_HOST_IGNORE(c0);
     KRML_CHECK_SIZE(sizeof(uint32_t), aLen + aLen);
-    uint32_t *tmp = (uint32_t *)alloca((aLen + aLen) * sizeof(uint32_t));
+    uint32_t *tmp = (uint32_t *)__builtin_alloca((aLen + aLen) * sizeof(uint32_t));
     memset(tmp, 0U, (aLen + aLen) * sizeof(uint32_t));
     for (uint32_t i = (uint32_t)0U; i < aLen; i++) {
         uint64_t res1 = (uint64_t)a[i] * (uint64_t)a[i];
@@ -423,7 +423,7 @@ Hacl_Bignum_Multiplication_bn_sqr_u64(ui
     uint64_t c0 = Hacl_Bignum_Addition_bn_add_eq_len_u64(aLen + aLen, res, res, res);
     KRML_HOST_IGNORE(c0);
     KRML_CHECK_SIZE(sizeof(uint64_t), aLen + aLen);
-    uint64_t *tmp = (uint64_t *)alloca((aLen + aLen) * sizeof(uint64_t));
+    uint64_t *tmp = (uint64_t *)__builtin_alloca((aLen + aLen) * sizeof(uint64_t));
     memset(tmp, 0U, (aLen + aLen) * sizeof(uint64_t));
     for (uint32_t i = (uint32_t)0U; i < aLen; i++) {
         FStar_UInt128_uint128 res1 = FStar_UInt128_mul_wide(a[i], a[i]);
