--- lib/vtls/mbedtls.c.orig	2024-03-26 07:42:20 UTC
+++ lib/vtls/mbedtls.c
@@ -602,10 +602,6 @@ mbed_connect_step1(struct Curl_cfilter *
   }
 
   mbedtls_ssl_init(&backend->ssl);
-  if(mbedtls_ssl_setup(&backend->ssl, &backend->config)) {
-    failf(data, "mbedTLS: ssl_init failed");
-    return CURLE_SSL_CONNECT_ERROR;
-  }
 
   /* new profile with RSA min key len = 1024 ... */
   mbedtls_ssl_conf_cert_profile(&backend->config,
@@ -639,6 +635,15 @@ mbed_connect_step1(struct Curl_cfilter *
 
   mbedtls_ssl_conf_rng(&backend->config, mbedtls_ctr_drbg_random,
                        &backend->ctr_drbg);
+
+  ret = mbedtls_ssl_setup(&backend->ssl, &backend->config);
+  if(ret) {
+    mbedtls_strerror(ret, errorbuf, sizeof(errorbuf));
+    failf(data, "ssl_setup failed - mbedTLS: (-0x%04X) %s",
+          -ret, errorbuf);
+    return CURLE_SSL_CONNECT_ERROR;
+  }
+
   mbedtls_ssl_set_bio(&backend->ssl, cf,
                       mbedtls_bio_cf_write,
                       mbedtls_bio_cf_read,