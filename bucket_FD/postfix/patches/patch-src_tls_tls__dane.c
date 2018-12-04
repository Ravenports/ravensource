--- src/tls/tls_dane.c.orig	2018-11-04 23:47:50 UTC
+++ src/tls/tls_dane.c
@@ -2127,7 +2127,7 @@ static SSL_CTX *ctx_init(const char *CAf
     tls_param_init();
     tls_check_version();
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     SSL_load_error_strings();
     SSL_library_init();
 #endif
