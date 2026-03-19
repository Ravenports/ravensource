--- lib/the_Foundation/src/tlsrequest.c.orig	2025-11-26 17:25:11 UTC
+++ lib/the_Foundation/src/tlsrequest.c
@@ -263,7 +263,9 @@ void init_Context(iContext *d) {
     SSL_load_error_strings();
     ERR_load_crypto_strings();
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
     ERR_load_BIO_strings();
+#endif
     d->ctx = SSL_CTX_new(TLS_client_method());
     if (!d->ctx) {
         iDebug("[TlsRequest] failed to initialize OpenSSL\n");
