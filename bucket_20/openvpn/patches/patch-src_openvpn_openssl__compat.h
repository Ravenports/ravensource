--- ./src/openvpn/openssl_compat.h.orig	2018-04-24 07:12:55 UTC
+++ ./src/openvpn/openssl_compat.h
@@ -715,7 +715,7 @@ SSL_CTX_get_max_proto_version(SSL_CTX *c
 }
 #endif /* SSL_CTX_get_max_proto_version */
 
-#ifndef SSL_CTX_set_min_proto_version
+#if !defined(SSL_CTX_set_min_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_min_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_min_proto_version(SSL_CTX *ctx, long tls_ver_min)
@@ -744,7 +744,7 @@ SSL_CTX_set_min_proto_version(SSL_CTX *c
 }
 #endif /* SSL_CTX_set_min_proto_version */
 
-#ifndef SSL_CTX_set_max_proto_version
+#if !defined(SSL_CTX_set_max_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_max_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_max_proto_version(SSL_CTX *ctx, long tls_ver_max)
