Support mbedtls 4.0 header relocation

--- src/stream.c.orig	2025-01-20 03:11:47 UTC
+++ src/stream.c
@@ -24,8 +24,8 @@
 #include "config.h"
 #endif
 
-#include <mbedtls/entropy.h>
-#include <mbedtls/ctr_drbg.h>
+#include <mbedtls/private/entropy.h>
+#include <mbedtls/private/ctr_drbg.h>
 #include <mbedtls/version.h>
 #define CIPHER_UNSUPPORTED "unsupported"
 
