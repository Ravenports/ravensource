--- lib/zip_crypto_openssl.c.orig	2018-03-11 17:00:53 UTC
+++ lib/zip_crypto_openssl.c
@@ -75,7 +75,7 @@ _zip_crypto_hmac_new(const zip_uint8_t *
         return NULL;
     }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000fL
+#if OPENSSL_VERSION_NUMBER < 0x1010000fL || defined(LIBRESSL_VERSION_NUMBER)
     if ((hmac  = (_zip_crypto_hmac_t *)malloc(sizeof(*hmac))) == NULL) {
         zip_error_set(error, ZIP_ER_MEMORY, 0);
         return NULL;
@@ -91,7 +91,7 @@ _zip_crypto_hmac_new(const zip_uint8_t *
 
     if (HMAC_Init_ex(hmac, secret, (int)secret_length, EVP_sha1(), NULL) != 1) {
         zip_error_set(error, ZIP_ER_INTERNAL, 0);
-#if OPENSSL_VERSION_NUMBER < 0x1010000fL
+#if OPENSSL_VERSION_NUMBER < 0x1010000fL || defined(LIBRESSL_VERSION_NUMBER)
         free(hmac);
 #else
         HMAC_CTX_free(hmac);
@@ -110,7 +110,7 @@ _zip_crypto_hmac_free(_zip_crypto_hmac_t
         return;
     }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000fL
+#if OPENSSL_VERSION_NUMBER < 0x1010000fL || defined(LIBRESSL_VERSION_NUMBER)
     HMAC_CTX_cleanup(hmac);
     _zip_crypto_clear(hmac, sizeof(*hmac));
     free(hmac);
