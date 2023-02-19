--- imtest/imtest.c.orig	2023-02-12 22:29:57 UTC
+++ imtest/imtest.c
@@ -511,7 +511,9 @@ static int tls_init_clientengine(int ver
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     SSL_CTX_set_options(tls_ctx, off);
     SSL_CTX_set_info_callback(tls_ctx, apps_ssl_info_callback);
 
