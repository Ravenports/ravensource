--- cargo-crates/libssh2-sys-0.2.23/libssh2/src/openssl.h.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/libssh2-sys-0.2.23/libssh2/src/openssl.h
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
 
