Fix build with LibreSSL.
Support pre-C23 compilers.

--- libraries/libldap/tls_o.c.orig	2026-08-06 17:17:48 UTC
+++ libraries/libldap/tls_o.c
@@ -51,7 +51,7 @@
 #endif
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 #define ASN1_STRING_data(x)	ASN1_STRING_get0_data(x)
 #endif
 
@@ -134,7 +134,7 @@ static void tlso_thr_init( void ) {}
 #endif
 #endif /* OpenSSL 1.1 */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 /*
  * OpenSSL 1.1 API and later makes the BIO method concrete types internal.
  */
@@ -230,7 +230,7 @@ tlso_init( void )
 	(void) tlso_seed_PRNG( lo->ldo_tls_randfile );
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 	SSL_load_error_strings();
 	SSL_library_init();
 	OpenSSL_add_all_digests();
@@ -283,7 +283,7 @@ static void
 tlso_ctx_ref( tls_ctx *ctx )
 {
 	tlso_ctx *c = (tlso_ctx *)ctx;
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 #define	SSL_CTX_up_ref(ctx)	CRYPTO_add( &(ctx->references), 1, CRYPTO_LOCK_SSL_CTX )
 #endif
 	SSL_CTX_up_ref( c );
@@ -543,7 +543,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 
 				while ((info = OSSL_STORE_load( sctx ))) {
 					switch (OSSL_STORE_INFO_get_type( info )) {
-					case OSSL_STORE_INFO_CERT:
+					case OSSL_STORE_INFO_CERT: {
 						X509 *cert = OSSL_STORE_INFO_get0_CERT( info );
 						X509_STORE *store = SSL_CTX_get_cert_store( ctx );
 						if ( !X509_STORE_add_cert( store, cert ) ) {
@@ -565,6 +565,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 							}
 						}
 						break;
+					}
 					default:
 						/* ignore other types */
 						break;
@@ -753,7 +754,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 						return -1;
 					}
 					break;
-				case OSSL_STORE_INFO_CERT:
+				case OSSL_STORE_INFO_CERT: {
 					X509 *cert = OSSL_STORE_INFO_get0_CERT(info);
 					int is_ca = X509_check_ca( cert );
 					if ( !is_ca && !SSL_CTX_use_certificate( ctx, cert )) {
@@ -773,7 +774,8 @@ tlso_ctx_init( struct ldapoptions *lo, s
 						return -1;
 					}
 					break;
-				case OSSL_STORE_INFO_CRL:
+				}
+				case OSSL_STORE_INFO_CRL: {
 					X509_STORE *x509_s = SSL_CTX_get_cert_store( ctx );
 					if ( !X509_STORE_add_crl( x509_s,
 							OSSL_STORE_INFO_get0_CRL(info) )) {
@@ -785,6 +787,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 						return -1;
 					}
 					break;
+				}
 				default:
 					/* ignore other types */
 					break;
@@ -931,7 +934,7 @@ tlso_session_my_dn( tls_session *sess, s
 	if (!x) return LDAP_INVALID_CREDENTIALS;
 	
 	xn = X509_get_subject_name(x);
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
 #else
@@ -967,7 +970,7 @@ tlso_session_peer_dn( tls_session *sess,
 		return LDAP_INVALID_CREDENTIALS;
 
 	xn = X509_get_subject_name(x);
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 	der_dn->bv_len = i2d_X509_NAME( xn, NULL );
 	der_dn->bv_val = xn->bytes->data;
 #else
@@ -1418,7 +1421,7 @@ struct tls_data {
 	Sockbuf_IO_Desc		*sbiod;
 };
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 #define BIO_set_init(b, x)	b->init = x
 #define BIO_set_data(b, x)	b->ptr = x
 #define BIO_clear_flags(b, x)	b->flags &= ~(x)
