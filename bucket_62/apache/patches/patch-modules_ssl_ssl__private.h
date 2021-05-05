--- modules/ssl/ssl_private.h.orig	2021-01-17 17:23:37 UTC
+++ modules/ssl/ssl_private.h
@@ -124,7 +124,7 @@
 #define MODSSL_SSL_METHOD_CONST
 #endif
 
-#if defined(LIBRESSL_VERSION_NUMBER)
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
 /* Missing from LibreSSL */
 #if LIBRESSL_VERSION_NUMBER < 0x2060000f
 #define SSL_CTRL_SET_MIN_PROTO_VERSION          123
