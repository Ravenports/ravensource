Fix build with LibreSSL.

--- libraries/libldap/tls_o.c.orig	2018-03-22 15:44:27 UTC
+++ libraries/libldap/tls_o.c
@@ -47,7 +47,7 @@
 #include <ssl.h>
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
 #define ASN1_STRING_data(x)	ASN1_STRING_get0_data(x)
 #endif
 
@@ -65,7 +65,7 @@ static void tlso_info_cb( const SSL *ssl
 static int tlso_verify_cb( int ok, X509_STORE_CTX *ctx );
 static int tlso_verify_ok( int ok, X509_STORE_CTX *ctx );
 static int tlso_seed_PRNG( const char *randfile );
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 /*
  * OpenSSL 1.1 API and later has new locking code
 */
@@ -116,7 +116,7 @@ static void tlso_thr_init( void ) {}
 #endif
 #endif /* OpenSSL 1.1 */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 /*
  * OpenSSL 1.1 API and later makes the BIO method concrete types internal.
  */
@@ -197,7 +197,7 @@ tlso_init( void )
 	(void) tlso_seed_PRNG( lo->ldo_tls_randfile );
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 	SSL_load_error_strings();
 	SSL_library_init();
 	OpenSSL_add_all_digests();
@@ -223,7 +223,7 @@ tlso_destroy( void )
 
 	BIO_meth_free( tlso_bio_method );
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 	EVP_cleanup();
 #if OPENSSL_VERSION_NUMBER < 0x10000000
 	ERR_remove_state(0);
@@ -249,7 +249,7 @@ static void
 tlso_ctx_ref( tls_ctx *ctx )
 {
 	tlso_ctx *c = (tlso_ctx *)ctx;
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 #define	SSL_CTX_up_ref(ctx)	CRYPTO_add( &(ctx->references), 1, CRYPTO_LOCK_SSL_CTX )
 #endif
 	SSL_CTX_up_ref( c );
@@ -411,7 +411,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 	SSL_CTX_set_verify( ctx, i,
 		lo->ldo_tls_require_cert == LDAP_OPT_X_TLS_ALLOW ?
 		tlso_verify_ok : tlso_verify_cb );
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 	SSL_CTX_set_tmp_rsa_callback( ctx, tlso_tmp_rsa_cb );
 #endif
 #ifdef HAVE_OPENSSL_CRL
@@ -508,7 +508,7 @@ tlso_session_my_dn( tls_session *sess, s
 	if (!x) return LDAP_INVALID_CREDENTIALS;
 	
 	xn = X509_get_subject_name(x);
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
 #else
@@ -544,7 +544,7 @@ tlso_session_peer_dn( tls_session *sess,
 		return LDAP_INVALID_CREDENTIALS;
 
 	xn = X509_get_subject_name(x);
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
 #else
@@ -765,7 +765,7 @@ struct tls_data {
 	Sockbuf_IO_Desc		*sbiod;
 };
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 #define BIO_set_init(b, x)	b->init = x
 #define BIO_set_data(b, x)	b->ptr = x
 #define BIO_clear_flags(b, x)	b->flags &= ~(x)
@@ -1170,7 +1170,7 @@ tlso_report_error( void )
 	}
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 static RSA *
 tlso_tmp_rsa_cb( SSL *ssl, int is_export, int key_length )
 {
