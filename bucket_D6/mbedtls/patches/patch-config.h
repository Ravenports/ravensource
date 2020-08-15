--- include/mbedtls/config.h.orig	2020-06-30 11:08:49 UTC
+++ include/mbedtls/config.h
@@ -1946,7 +1946,7 @@
  *
  * Uncomment this to enable pthread mutexes.
  */
-//#define MBEDTLS_THREADING_PTHREAD
+#define MBEDTLS_THREADING_PTHREAD
 
 /**
  * \def MBEDTLS_USE_PSA_CRYPTO
@@ -3248,7 +3248,7 @@
  *
  * Enable this layer to allow use of mutexes within mbed TLS
  */
-//#define MBEDTLS_THREADING_C
+#define MBEDTLS_THREADING_C
 
 /**
  * \def MBEDTLS_TIMING_C
