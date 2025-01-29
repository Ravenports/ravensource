--- imap/tls.c.orig	2025-01-22 01:00:22 UTC
+++ imap/tls.c
@@ -781,12 +781,14 @@ EXPORTED int     tls_init_serverengine(c
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 
     const char *tls_versions = config_getstring(IMAPOPT_TLS_VERSIONS);
 
     if (strstr(tls_versions, "tls1_3") == NULL) {
-#if (OPENSSL_VERSION_NUMBER >= 0x1010100fL)
+#if (OPENSSL_VERSION_NUMBER >= 0x1010100fL) && !defined(LIBRESSL_VERSION_NUMBER)
         //syslog(LOG_DEBUG, "TLS server engine: Disabled TLSv1.3");
         off |= SSL_OP_NO_TLSv1_3;
 #else
@@ -1567,7 +1569,9 @@ HIDDEN int tls_init_clientengine(int ver
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 
     SSL_CTX_set_options(c_ctx, off);
     SSL_CTX_set_info_callback(c_ctx, apps_ssl_info_callback);
