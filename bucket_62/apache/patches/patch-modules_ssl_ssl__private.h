--- modules/ssl/ssl_private.h.orig	2021-09-09 15:22:23 UTC
+++ modules/ssl/ssl_private.h
@@ -125,7 +125,7 @@
 #define MODSSL_SSL_METHOD_CONST
 #endif
 
-#if defined(LIBRESSL_VERSION_NUMBER)
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
 /* Missing from LibreSSL */
 #if LIBRESSL_VERSION_NUMBER < 0x2060000f
 #define SSL_CTRL_SET_MIN_PROTO_VERSION          123
