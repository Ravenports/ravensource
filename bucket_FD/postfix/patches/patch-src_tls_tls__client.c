--- src/tls/tls_client.c.orig	2018-11-17 22:33:15 UTC
+++ src/tls/tls_client.c
@@ -299,7 +299,7 @@ TLS_APPL_STATE *tls_client_init(const TL
      */
     tls_check_version();
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
     /*
      * Initialize the OpenSSL library by the book! To start with, we must
@@ -433,7 +433,7 @@ TLS_APPL_STATE *tls_client_init(const TL
     /*
      * 2015-12-05: Ephemeral RSA removed from OpenSSL 1.1.0-dev
      */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
     /*
      * According to the OpenSSL documentation, temporary RSA key is needed
