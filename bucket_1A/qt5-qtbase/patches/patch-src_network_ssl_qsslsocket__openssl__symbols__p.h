--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2017-11-30 13:49:46 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -232,7 +232,7 @@ BIO *q_BIO_new_mem_buf(void *a, int b);
 int q_BIO_read(BIO *a, void *b, int c);
 Q_AUTOTEST_EXPORT int q_BIO_write(BIO *a, const void *b, int c);
 int q_BN_num_bits(const BIGNUM *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if QT_CONFIG(opensslv11)
 int q_BN_is_word(BIGNUM *a, BN_ULONG w);
 #else
 // BN_is_word is implemented purely as a
@@ -245,7 +245,7 @@ int q_BN_is_word(BIGNUM *a, BN_ULONG w);
 //
 // Users are required to include <openssl/bn.h>.
 #define q_BN_is_word BN_is_word
-#endif // OPENSSL_VERSION_NUMBER >= 0x10100000L
+#endif // QT_CONFIG
 BN_ULONG q_BN_mod_word(const BIGNUM *a, BN_ULONG w);
 #ifndef OPENSSL_NO_EC
 const EC_GROUP* q_EC_KEY_get0_group(const EC_KEY* k);
