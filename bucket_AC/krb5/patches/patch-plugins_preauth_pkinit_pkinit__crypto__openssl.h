--- plugins/preauth/pkinit/pkinit_crypto_openssl.h.orig	2019-01-08 16:02:37 UTC
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.h
@@ -46,7 +46,8 @@
 #include <openssl/asn1.h>
 #include <openssl/pem.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if (defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+     !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/asn1t.h>
 #else
 #include <openssl/asn1_mac.h>
