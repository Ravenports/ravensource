--- modules/ssl/ssl_engine_init.c.orig	2024-06-21 14:28:25 UTC
+++ modules/ssl/ssl_engine_init.c
@@ -617,7 +617,7 @@ static apr_status_t ssl_init_ctx_protoco
     char *cp;
     int protocol = mctx->protocol;
     SSLSrvConfigRec *sc = mySrvConfig(s);
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
     int prot;
 #endif
 
