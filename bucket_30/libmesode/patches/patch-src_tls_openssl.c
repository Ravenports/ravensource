diff --git src/tls_openssl.c src/tls_openssl.c
index 83e52f9..20badd7 100644
--- src/tls_openssl.c.orig	2020-09-29 15:25:04 UTC
+++ src/tls_openssl.c
@@ -64,7 +64,7 @@ static void _tls_dump_cert_info(tls_t *t
 
 void tls_initialize(void)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     SSL_library_init();
     SSL_load_error_strings();
 #else
@@ -79,14 +79,14 @@ void tls_shutdown(void)
      * openssl after libstrophe finalization. Maybe better leak some fixed
      * memory rather than cause random crashes of the main program.
      */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ERR_free_strings();
     EVP_cleanup();
     CRYPTO_cleanup_all_ex_data();
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
     SSL_COMP_free_compression_methods();
 #endif
-#if OPENSSL_VERSION_NUMBER < 0x10000000L
+#if OPENSSL_VERSION_NUMBER < 0x10000000L || defined(LIBRESSL_VERSION_NUMBER)
     ERR_remove_state(0);
 #else
     ERR_remove_thread_state(NULL);
@@ -376,7 +376,7 @@ tls_t *tls_new(xmpp_conn_t *conn)
         /* Trust server's certificate when user sets the flag explicitly. */
         mode = conn->tls_trust ? SSL_VERIFY_NONE : SSL_VERIFY_PEER;
         SSL_set_verify(tls->ssl, mode, 0);
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L || !defined(LIBRESSL_VERSION_NUMBER)
         /* Hostname verification is supported in OpenSSL 1.0.2 and newer. */
         param = SSL_get0_param(tls->ssl);
 
