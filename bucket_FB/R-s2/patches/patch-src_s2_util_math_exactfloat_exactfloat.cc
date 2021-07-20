--- src/s2/util/math/exactfloat/exactfloat.cc.orig	2021-01-04 12:00:17 UTC
+++ src/s2/util/math/exactfloat/exactfloat.cc
@@ -108,7 +108,7 @@ inline static uint64 BN_ext_get_uint64(c
 #endif
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 // Count the number of low-order zero bits in the given BIGNUM (ignoring its
 // sign).  Returns 0 if the argument is zero.
