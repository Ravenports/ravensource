--- modules/ssl/ssl_private.h.orig	2026-11-03 15:50:09 UTC
+++ modules/ssl/ssl_private.h
@@ -151,7 +151,7 @@
 #define MODSSL_X509_EXT_CONST
 #endif
 
-#if defined(LIBRESSL_VERSION_NUMBER)
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
 /* Missing from LibreSSL */
 #if LIBRESSL_VERSION_NUMBER < 0x2060000f
 #define SSL_CTRL_SET_MIN_PROTO_VERSION          123
