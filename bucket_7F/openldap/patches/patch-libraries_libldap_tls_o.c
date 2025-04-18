Fix build with LibreSSL.

--- libraries/libldap/tls_o.c.orig	2024-05-21 17:19:11 UTC
+++ libraries/libldap/tls_o.c
@@ -48,7 +48,7 @@
 #include <openssl/dh.h>
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 #define ASN1_STRING_data(x)	ASN1_STRING_get0_data(x)
 #endif
 
@@ -131,7 +131,7 @@ static void tlso_thr_init( void ) {}
 #endif
 #endif /* OpenSSL 1.1 */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 /*
  * OpenSSL 1.1 API and later makes the BIO method concrete types internal.
  */
@@ -222,7 +222,7 @@ tlso_init( void )
 	(void) tlso_seed_PRNG( lo->ldo_tls_randfile );
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 	SSL_load_error_strings();
 	SSL_library_init();
 	OpenSSL_add_all_digests();
@@ -275,7 +275,7 @@ static void
 tlso_ctx_ref( tls_ctx *ctx )
 {
 	tlso_ctx *c = (tlso_ctx *)ctx;
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 #define	SSL_CTX_up_ref(ctx)	CRYPTO_add( &(ctx->references), 1, CRYPTO_LOCK_SSL_CTX )
 #endif
 	SSL_CTX_up_ref( c );
@@ -750,7 +750,7 @@ tlso_session_my_dn( tls_session *sess, s
 	if (!x) return LDAP_INVALID_CREDENTIALS;
 	
 	xn = X509_get_subject_name(x);
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
 #else
@@ -786,7 +786,7 @@ tlso_session_peer_dn( tls_session *sess,
 		return LDAP_INVALID_CREDENTIALS;
 
 	xn = X509_get_subject_name(x);
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
 #else
@@ -1225,7 +1225,7 @@ struct tls_data {
 	Sockbuf_IO_Desc		*sbiod;
 };
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 #define BIO_set_init(b, x)	b->init = x
 #define BIO_set_data(b, x)	b->ptr = x
 #define BIO_clear_flags(b, x)	b->flags &= ~(x)
