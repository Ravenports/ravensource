--- deps/ntlmclient/crypt_openssl.c.orig	2021-09-02 03:06:19 UTC
+++ deps/ntlmclient/crypt_openssl.c
@@ -44,7 +44,7 @@ static inline void HMAC_CTX_free(HMAC_CT
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L || defined(CRYPT_OPENSSL_DYNAMIC)
+#if !defined(LIBRESSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10100000L || defined(CRYPT_OPENSSL_DYNAMIC))
 
 static inline void HMAC_CTX_cleanup(HMAC_CTX *ctx)
 {
