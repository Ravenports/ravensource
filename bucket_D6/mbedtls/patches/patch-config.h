--- include/mbedtls/config.h.orig	2021-03-12 16:55:26 UTC
+++ include/mbedtls/config.h
@@ -2090,7 +2090,7 @@
  *
  * Uncomment this to enable pthread mutexes.
  */
-//#define MBEDTLS_THREADING_PTHREAD
+#define MBEDTLS_THREADING_PTHREAD
 
 /**
  * \def MBEDTLS_USE_PSA_CRYPTO
@@ -3414,7 +3414,7 @@
  *
  * Enable this layer to allow use of mutexes within mbed TLS
  */
-//#define MBEDTLS_THREADING_C
+#define MBEDTLS_THREADING_C
 
 /**
  * \def MBEDTLS_TIMING_C
