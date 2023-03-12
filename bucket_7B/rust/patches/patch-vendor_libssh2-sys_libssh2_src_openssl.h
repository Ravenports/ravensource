--- vendor/libssh2-sys/libssh2/src/openssl.h.orig	2023-03-06 18:39:30 UTC
+++ vendor/libssh2-sys/libssh2/src/openssl.h
@@ -57,8 +57,9 @@
 #include <openssl/pem.h>
 #include <openssl/rand.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
-    !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && \
+    !defined(LIBRESSL_VERSION_NUMBER)) || \
+    LIBRESSL_VERSION_NUMBER >= 0x3050000fL
 # define HAVE_OPAQUE_STRUCTS 1
 #endif
 
