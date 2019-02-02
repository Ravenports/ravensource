--- vio/viosslfactories.cc.orig	2019-01-25 22:33:03 UTC
+++ vio/viosslfactories.cc
@@ -38,6 +38,7 @@
 
 #ifdef HAVE_OPENSSL
 #include <openssl/dh.h>
+#include <openssl/crypto.h>
 
 #define TLS_VERSION_OPTION_SIZE 256
 #define SSL_CIPHER_LIST_SIZE 4096
@@ -136,7 +137,7 @@ static DH *get_dh2048(void) {
     BIGNUM *p = BN_bin2bn(dh2048_p, sizeof(dh2048_p), NULL);
     BIGNUM *g = BN_bin2bn(dh2048_g, sizeof(dh2048_g), NULL);
     if (!p || !g
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
         || !DH_set0_pqg(dh, p, NULL, g)
 #endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
     ) {
@@ -144,7 +145,7 @@ static DH *get_dh2048(void) {
       DH_free(dh);
       return NULL;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     dh->p = p;
     dh->g = g;
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
@@ -429,7 +430,7 @@ void ssl_start() {
   }
 }
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
 /**
   Set fips mode in openssl library,
   When we set fips mode ON/STRICT, it will perform following operations:
@@ -452,6 +453,10 @@ int set_fips_mode(const uint fips_mode,
   int rc = -1;
   unsigned int fips_mode_old = -1;
   unsigned long err_library = 0;
+#if defined(LIBRESSL_VERSION_NUMBER)
+  err_string="LibreSSL deosn't have FIPS_mode functionas";
+  goto EXIT;
+#else
   if (fips_mode > 2) {
     goto EXIT;
   }
@@ -465,6 +470,7 @@ int set_fips_mode(const uint fips_mode,
     ERR_error_string_n(err_library, err_string, OPENSSL_ERROR_LENGTH - 1);
     err_string[OPENSSL_ERROR_LENGTH - 1] = '\0';
   }
+#endif
 EXIT:
   return rc;
 }
